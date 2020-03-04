#include "modbustool.h"
#include "ui_modbustool.h"

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
