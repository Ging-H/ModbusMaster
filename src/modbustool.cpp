#include "modbustool.h"
#include "ui_modbustool.h"
#include <QDebug>

ModbusTool::ModbusTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModbusTool)
{
    ui->setupUi(this);
    currentPort = new BaseSerialComm();
    this->initComboBox_Config();
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler( QSerialPort::SerialPortError)));
    this->setLineEditInputType();
}

ModbusTool::~ModbusTool()
{
    delete ui;
}


/*   初始化了串口设置当中的下拉列表(ComboBox) */
void ModbusTool::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}

/* 刷新按钮点击 槽函数 */
void ModbusTool::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/* 打开串口 槽函数*/
void ModbusTool::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort -> setDTRState(false);
            currentPort -> setRTSState(false);
            /* 配置端口的波特率等参数 */
            this->configPort();
            connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_RxCallback()));// 有数据就直接接收显示
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}

/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void ModbusTool::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
}

/* 串口错误信息处理 */
void ModbusTool::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}
/* 串口接收数据,存储在dataBuf当中 */
void ModbusTool::slots_RxCallback()
{
    QByteArray tmp = currentPort->readAll();
    rxDataBuf.append(tmp);

}
/*----------------------------------------------------------------------*/
/* 设定QLineEdit的编辑事件,限制输入长度,超过这个长度就自动跳转到下一个QLineEdit */
/**
 * @brief ModbusTool::setLineEditInputType 将QLineEdit限制为只能输入十六进制字符
 */
void ModbusTool::setLineEditInputType()
{
    QRegExp regExp("[a-fA-F0-9 ]*"); // 匹配十六进制字符和空格
    QRegExpValidator *reg = new QRegExpValidator(regExp,this);
    ui->txt03SlaveAddr->setValidator(reg);// 设定正则表达式
    ui->txt03RegAddr->setValidator(reg);
    ui->txt03RegNum->setValidator(reg);

    ui->txt04SlaveAddr->setValidator(reg);// 设定正则表达式
    ui->txt04RegAddr->setValidator(reg);
    ui->txt04RegNum->setValidator(reg);

    ui->txt06SlaveAddr->setValidator(reg);// 设定正则表达式
    ui->txt06RegAddr->setValidator(reg);
    ui->txt06Value->setValidator(reg);

    ui->txtOtherValue->setValidator(reg);// 设定正则表达式
}

/*  03H指令   */

/**
 * @brief ModbusTool::on_txt03SlaveAddr_textChanged 限制 txt03SlaveAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt03SlaveAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>2 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt03RegAddr->setFocus();
        ui->txt03RegAddr->setText(last);
        ui->txt03SlaveAddr->setText(tmp);
    }
}

/**
 * @brief ModbusTool::on_txt03RegAddr_textChanged 限制txt03RegAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt03RegAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt03RegNum->setFocus();
        ui->txt03RegNum->setText(last);
        ui->txt03RegAddr->setText(tmp);
    }
}

void ModbusTool::on_txt03RegNum_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        tmp.chop(1);
        ui->txt03RegNum->setText(tmp);
    }
}


/*  04H指令   */

/**
 * @brief ModbusTool::on_txt04SlaveAddr_textChanged 限制 txt04SlaveAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt04SlaveAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>2 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt04RegAddr->setFocus();
        ui->txt04RegAddr->setText(last);
        ui->txt04SlaveAddr->setText(tmp);
    }
}

/**
 * @brief ModbusTool::on_txt04RegAddr_textChanged 限制txt04RegAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt04RegAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt04RegNum->setFocus();
        ui->txt04RegNum->setText(last);
        ui->txt04RegAddr->setText(tmp);
    }
}

void ModbusTool::on_txt04RegNum_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        tmp.chop(1);
        ui->txt04RegNum->setText(tmp);
    }
}

/*  06H指令   */

/**
 * @brief ModbusTool::on_txt06SlaveAddr_textChanged 限制 txt06SlaveAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt06SlaveAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>2 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt06RegAddr->setFocus();
        ui->txt06RegAddr->setText(last);
        ui->txt06SlaveAddr->setText(tmp);
    }
}

/**
 * @brief ModbusTool::on_txt06RegAddr_textChanged 限制txt06RegAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt06RegAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt06Value->setFocus();
        ui->txt06Value->setText(last);
        ui->txt06RegAddr->setText(tmp);
    }
}

void ModbusTool::on_txt06Value_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        tmp.chop(1);
        ui->txt06Value->setText(tmp);
    }
}


/*  10H指令   */

/**
 * @brief ModbusTool::on_txt10SlaveAddr_textChanged 限制 txt10SlaveAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt10SlaveAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>2 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt10RegAddr->setFocus();
        ui->txt10RegAddr->setText(last);
        ui->txt10SlaveAddr->setText(tmp);
    }
}

/**
 * @brief ModbusTool::on_txt10RegAddr_textChanged 限制txt10RegAddr 输入字符长度
 * @param arg1 输入的字符
 */
void ModbusTool::on_txt10RegAddr_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt10RegNum->setFocus();
        ui->txt10RegNum->setText(last);
        ui->txt10RegAddr->setText(tmp);
    }
}

void ModbusTool::on_txt10RegNum_textChanged(const QString &arg1)
{
    QString tmp = arg1;
    if(arg1.size()>4 ){
        QString last = tmp.right(1);
        tmp.chop(1);
        ui->txt10Value->setFocus();
        ui->txt10Value->setText(last);
        ui->txt10RegNum->setText(tmp);
    }
}

/*------------------------ 点击按钮事件处理 ---------------------*/

/**
 * @brief ModbusTool::on_btnOtherSend_clicked 发送通用指令
 */
void ModbusTool::on_btnOtherSend_clicked()
{
    QString tmp = ui->txtOtherValue->text();
    if(tmp.isEmpty()){
        return ;
    }
    tmp.remove(QRegExp ("\\s")); // delete space
    QByteArray txbuf = QByteArray::fromHex(tmp.toLocal8Bit());
    this->sendFrame(txbuf);
}
/**
 * @brief ModbusTool::on_btn03Send_clicked 发送03指令
 */
void ModbusTool::on_btn03Send_clicked()
{
    if(!currentPort->isOpen()) return ;
    QString strSlaverAddr = ui->txt03SlaveAddr->text();
    QString strRegAddr = ui->txt03RegAddr->text();
    QString strRegNum = ui->txt03RegNum->text();

    if(strSlaverAddr.isEmpty()) return ;
    if(strRegAddr.isEmpty())    return ;
    if(strRegNum.isEmpty())     return ;

    quint16 slaverAddr = strSlaverAddr.toInt(nullptr, 16);
    quint16 regAddr    = strRegAddr.toInt(nullptr, 16);
    quint16 regNum     = strRegNum.toInt(nullptr, 16);

    QByteArray txbuf;
    txbuf.append(slaverAddr);
    txbuf.append(0x03);
    txbuf.append(regAddr>>8);
    txbuf.append(regAddr);
    txbuf.append(regNum>>8);
    txbuf.append(regNum);

   this->sendFrame(txbuf);
}
/**
 * @brief ModbusTool::on_btn04Send_clicked 发送04指令
 */
void ModbusTool::on_btn04Send_clicked()
{
    if(!currentPort->isOpen()) return ;
    QString strSlaverAddr = ui->txt04SlaveAddr->text();
    QString strRegAddr = ui->txt04RegAddr->text();
    QString strRegNum = ui->txt04RegNum->text();

    if(strSlaverAddr.isEmpty()) return ;
    if(strRegAddr.isEmpty())    return ;
    if(strRegNum.isEmpty())     return ;

    quint16 slaverAddr = strSlaverAddr.toInt(nullptr, 16);
    quint16 regAddr    = strRegAddr.toInt(nullptr, 16);
    quint16 regNum     = strRegNum.toInt(nullptr, 16);

    QByteArray txbuf;
    txbuf.append(slaverAddr);
    txbuf.append(0x03);// insert cmd 0x04
    txbuf.append(regAddr>>8);
    txbuf.append(regAddr);
    txbuf.append(regNum>>8);
    txbuf.append(regNum);

   this->sendFrame(txbuf);

}
/**
 * @brief ModbusTool::on_btn06Send_clicked 发送06指令
 */
void ModbusTool::on_btn06Send_clicked()
{
    if(!currentPort->isOpen()) return ;
    QString strSlaverAddr = ui->txt06SlaveAddr->text();
    QString strRegAddr = ui->txt06RegAddr->text();
    QString strValue = ui->txt06Value->text();

    if(strSlaverAddr.isEmpty()) return ;
    if(strRegAddr.isEmpty())    return ;
    if(strValue.isEmpty())     return ;

    quint16 slaverAddr = strSlaverAddr.toInt(nullptr, 16);
    quint16 regAddr    = strRegAddr.toInt(nullptr, 16);
    quint16 regValue     = strValue.toInt(nullptr, 16);

    QByteArray txbuf;
    txbuf.append(slaverAddr);
    txbuf.append(0x06);// insert cmd 0x06
    txbuf.append(regAddr>>8);
    txbuf.append(regAddr);
    txbuf.append(regValue>>8);
    txbuf.append(regValue);

   this->sendFrame(txbuf);
}
/**
 * @brief ModbusTool::on_btn10Send_clicked 发送10指令
 */
void ModbusTool::on_btn10Send_clicked()
{
    if(!currentPort->isOpen()) return ;
    QString strSlaverAddr = ui->txt10SlaveAddr->text();
    QString strRegAddr = ui->txt10RegAddr->text();
    QString strRegNum = ui->txt10RegNum->text();
    QString strValue = ui->txt10RegNum->text();

    if(strSlaverAddr.isEmpty()) return ;
    if(strRegAddr.isEmpty())    return ;
    if(strRegNum.isEmpty())     return ;
    if(strValue.isEmpty())     return ;

    quint16 slaverAddr = strSlaverAddr.toInt(nullptr, 16);
    quint16 regAddr    = strRegAddr.toInt(nullptr, 16);
    quint16 regNum     = strRegNum.toInt(nullptr, 16);


    QByteArray txbuf;
    txbuf.append(slaverAddr);
    txbuf.append(0x10);// insert cmd 0x10
    txbuf.append(regAddr>>8);
    txbuf.append(regAddr);
    txbuf.append(regNum>>8);
    txbuf.append(regNum);

    quint8 byteNum = 0;
    byteNum = ui->txt10RegNum->text().toInt(nullptr,16);
    byteNum *= 2;
    txbuf.append(byteNum);    // insert byteNum

    QString tmp = ui->txt10Value->text();
    tmp.remove(QRegExp ("\\s")); // delete space
    QByteArray array = QByteArray::fromHex(tmp.toLocal8Bit());

    txbuf.append(array);
    this->sendFrame(txbuf);
}

/**
 * @brief ModbusTool::sendFrame 发送数据帧
 * @param txbuf 待发送的数据（不含校验码）
 */
void ModbusTool::sendFrame(QByteArray txbuf)
{
    if( ui->rdbRTU->isChecked() ){
        if( ui->ckbInsertCRC->isChecked() ){
            quint16 CRC = crc16_modbus_calc((quint8*)txbuf.data(), txbuf.size());
            txbuf.append(CRC);
            txbuf.append(CRC>>8);
        }
        currentPort->write(txbuf,txbuf.size());
        ui->txtMessage->append(txbuf.toHex(' ').toUpper().prepend("Tx: "));
    }else{
        /* TODO: 改为添加LRC校验码 */
        if( ui->ckbInsertCRC->isChecked() ){
            quint16 CRC = crc16_modbus_calc((quint8*)txbuf.data(), txbuf.size());
            txbuf.append(CRC);
            txbuf.append(CRC>>8);
        }
        QByteArray tmp = txbuf.toHex().toUpper().prepend(":");
        currentPort->write(tmp,tmp.size());
        ui->txtMessage->append(tmp.prepend("Tx: "));
    }
}

/******************************************************************************
 * Name:    CRC-16/MODBUS       x16+x15+x2+1
 * Poly:    0x8005
 * Init:    0xFFFF
 * Refin:   True
 * Refout:  True
 * Xorout:  0x0000
 * Note:
 *****************************************************************************/
static quint16 crc16Modbus_table[256] = {
0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241, 0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641, 0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41, 0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41, 0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640, 0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41, 0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640, 0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241, 0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40, 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641, 0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040,
};
quint16 ModbusTool::crc16_modbus_calc(quint8 *data, quint32 length)
{
    uint16_t tmp = 0;
    uint16_t crc = 0xFFFF;                // Initial value
    while(length--)
    {
        tmp =  (0x00FF & crc) ^ (*data++);    // crc ^= *data; data++;
        crc = (crc >> 8) ^ crc16Modbus_table[tmp&0xFF];
    }
    return crc; // crc
}


