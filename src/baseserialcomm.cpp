#include "baseserialcomm.h"

#include <QMessageBox>
#include <QMetaEnum>
#include <QDebug>

#ifdef USE_CRC_MODULE
#include "checksum.h"
#endif


// CRC16_MODBUS
// CRC 高位字节值表
static const quint8 auchCRCHi[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
} ;
// CRC 低位字节值表
static const quint8 auchCRCLo[] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

BaseSerialComm::BaseSerialComm(QSerialPort *parent) : QSerialPort(parent)
{
}

/* BaudRate 波特率 在控件中列出支持的波特率 */
void BaseSerialComm::listBaudRate(QComboBox *cbbBaud)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaseSerialComm::BaudRate>();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        cbbBaud->addItem(tmp, mtaEnum.value(i));
//        qDebug() << tmp;
        /* 删除未知值 */
        if(mtaEnum.value(i)== BaseSerialComm::BaudRate::UnknownBaud ){
            cbbBaud->removeItem(i);
        }
    }
    cbbBaud->setCurrentText("115200"); // 设定默认值
}

void BaseSerialComm::listDataBit(QComboBox *cbbDataBit)
{

    QString tmp;
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaseSerialComm::DataBits>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        cbbDataBit->addItem(tmp, mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::DataBits::UnknownDataBits )
            cbbDataBit->removeItem(i);
    }
    cbbDataBit->setCurrentText("8"); // 设定默认值
}

/* Parity 校验*/
void BaseSerialComm::listVerify(QComboBox *cbbVerify)
{
    /* 获取枚举元信息,并且与下拉列表 cbbVerify的item 绑定 */
    QMetaEnum mtaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) { // 遍历每个枚举值,获得text和data,添加到item中
        cbbVerify->addItem(mtaEnum.key(i), mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::Parity::UnknownParity )
            cbbVerify->removeItem(i);
    }
    cbbVerify->setCurrentText("NoParity"); // 设定默认值
}

/* StopBits 停止位 */
void BaseSerialComm::listStopBit(QComboBox *cbbStopBit)
{
    /* StopBits 停止位 */
    QMetaEnum mtaEnum = QMetaEnum::fromType < BaseSerialComm::StopBits >();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        if(mtaEnum.value(i) == 3)
            tmp = "1.5";  // 用3表示1.5个停止位
        cbbStopBit->addItem(tmp, mtaEnum.value(i));

        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::StopBits::UnknownStopBits )
            cbbStopBit->removeItem(i);
    }
    cbbStopBit->setCurrentText("1"); // 设定默认值
}



/* 更新 端口号 控件 */
void BaseSerialComm::listPortNum(QComboBox *cbbPortNum)
{
    QStringList portList;
    qint32 len = 0;   // list中最大的字符宽度

    portList.clear(); // 清空列表
    searchPort(portList);                      // 搜索可用的串口和描述
    if(portList.empty() == false){
        cbbPortNum->addItems(portList);    // 添加到ComboBox
        foreach(const QString &item, portList) // 遍历list每一项
        {
            if(len < item.toLocal8Bit().length() ) // 获取字符宽度
                len = item.toLocal8Bit().length();
        }
        qint32 fontSize = cbbPortNum->font().pointSize(); // 获取所用字体大小
        cbbPortNum->view()->setFixedWidth( len * fontSize * 0.75 ); // 调整显示宽度,字符数*字符宽度*0.75

    }
    else{
        QMessageBox::information(NULL, "无串口设备",  "没有搜索到串口设备", 0, 0);
    }
}
/* 终止符 控件 */
void BaseSerialComm::listTerminator(QComboBox *cbbTerminator)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaseSerialComm::Terminator>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        cbbTerminator->addItem(mtaEnum.key(i), mtaEnum.value(i));
        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::Terminator::UnknownTerminator)
            cbbTerminator->removeItem(i);
    }
    cbbTerminator->setCurrentText("NONE"); // 设定默认值
}
/* 校验字符类型 控件 */
void BaseSerialComm::listVerifyStyle(QComboBox *cbbVerifyStyle)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaseSerialComm::VerifyStyle>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        if(i == 0){
            cbbVerifyStyle->addItem("添加校验码", mtaEnum.value(i));
        }else{
            cbbVerifyStyle->addItem(mtaEnum.key(i), mtaEnum.value(i));
        }
        /* 删除未知值 */
        if(mtaEnum.value(i) == BaseSerialComm::VerifyStyle::UnknownStyle)
            cbbVerifyStyle->removeItem(i);
    }
    cbbVerifyStyle->setCurrentText("添加校验码"); // 设定默认值
}
/* 搜索端口号,返回串口列表 */
void BaseSerialComm::searchPort(QStringList &portList)
{
    portList.clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        portList << info.portName() + " " + info.description();
    }
}

/* 设置DTR状态 */
void BaseSerialComm::setDTRState(bool set)
{
    this->setDataTerminalReady(set);
}

/* 设置RTS状态 */
void BaseSerialComm::setRTSState(bool set)
{
    this->setRequestToSend(set);
}

/* 读取串口缓存中的数据 ,返回0代表没有接收到数据*/
qint32 BaseSerialComm::readData(QByteArray &rxBuffer)
{
    rxBuffer = this->readAll();
    if(rxBuffer.isEmpty()){
        return 0;
    }
    else {
        return rxBuffer.length();
    }
}

/* 往串口写入数据 */
/* 返回-1代表写入错误*/
qint32 BaseSerialComm::writtenData(QString txBuffer)
{
    QByteArray tmpBuffer = txBuffer.toLatin1();
    return this->write(tmpBuffer);
}

/* 插入结束符 */
void BaseSerialComm::insertTerminator(QByteArray &buffer,BaseSerialComm::Terminator terminator)
{
    if(buffer.isEmpty())
        return;
    if(terminator != NONE){
        switch(terminator){
        case CRLF_0x0D0A:
            buffer.append(CR_0x0D);
            buffer.append(LF_0xOA);
            break;
        case CR_0x0D:
            buffer.append(CR_0x0D);
            break;
        case LF_0xOA:
            buffer.append(LF_0xOA);
            break;
        default:break;
        }
    }
}
/* 检查src中字符是否符合Hex规则表达式 */
bool BaseSerialComm::isHexString(QString src)
{
    bool isMatch = true;
    QRegExp regExp("[a-f0-9A-F ]*");
    isMatch = regExp.exactMatch(src);
    return isMatch;
}

/* 插入校验码 */
QByteArray BaseSerialComm::insertVerify(QByteArray &buf, int start, int end, int VerifyStyle)
{
    quint8 verifyCode8;
    QByteArray verifyCode16;
    QByteArray verifyCode32;

    /* 限定数据范围 */
    if(end > buf.size()){
        end  = buf.size();
    }
    if(start == 0)
        start = 1;
    qint32 size = buf.size()-end-start+1;

    switch(VerifyStyle){
    case ADD8:// 累加和
        verifyCode8 = verifyADD8( buf.mid(start - 1, size));
        buf.insert(buf.size()-end, verifyCode8);
        verifyCode16.clear();
        verifyCode16.append(verifyCode8);
        return verifyCode16.toHex().toUpper(); // 返回校验码字符串
    case NADD8:// 负累加和
        verifyCode8 = verifyADD8( buf.mid(start - 1, size));
        verifyCode8 = (~verifyCode8) + 1;
        buf.insert(buf.size()-end, verifyCode8);
        verifyCode16.clear();
        verifyCode16.append(verifyCode8);
        return verifyCode16.toHex().toUpper(); // 返回校验码字符串
    case XOR8:// 异或
        verifyCode8 = verifyXOR8( buf.mid(start - 1, size));
        buf.insert(buf.size()-end, verifyCode8);
        verifyCode16.clear();
        verifyCode16.append(verifyCode8);
        return verifyCode16.toHex().toUpper(); // 返回校验码字符串

    case CRC_Modbus:// CRC16 Mudbus

        verifyCode16 = verifyCRC16( buf.mid(start - 1, size)); // TODO: LRC校验
        buf.insert(buf.size()-end, verifyCode16);
        return verifyCode16.toHex().toUpper();
#ifdef USE_CRC_MODULE
    case  CRC_Xmodem:
        verifyCode16 = verifyCRC16_CCITT( buf.mid(start - 1, size));
        buf.insert(buf.size()-end, verifyCode16);
        return verifyCode16.toHex().toUpper();

    case CRC32:
        verifyCode32 = verifyCRC32( buf.mid(start - 1, size));
        buf.insert(buf.size()-end, verifyCode32);
        return verifyCode32.toHex().toUpper();

    case LRC:
        verifyCode16 = verifyLRC(buf.mid(start - 1, size) );
        buf.insert(buf.size()-end, verifyCode16);
        return verifyCode16.toHex().toUpper();
    default:break;
#endif
    }
    return NULL;
}

/* 添加校验码 ADD8 */
quint8 BaseSerialComm::verifyADD8(QByteArray buf)
{
    quint8 retVal = 0;
    foreach(quint8 c, buf){
        retVal += c;
    }
    return retVal;
}

/* 添加校验码 XOR8 */
quint8 BaseSerialComm::verifyXOR8(QByteArray buf)
{
    quint8 retVal = 0;
    foreach(quint8 c, buf){
        retVal ^= c;
    }
    return retVal;
}


/* 添加校验码 Modbus CRC16 */
QByteArray BaseSerialComm::verifyCRC16(QByteArray buf)
{
    QByteArray a;

    quint8 uchCRCHi = 0xFF;
    quint8 uchCRCLo = 0xFF;
    quint16 uIndex;
    foreach (quint8 c, buf){
        uIndex = uchCRCLo ^ c;
        uchCRCLo = uchCRCHi^auchCRCHi[uIndex];
        uchCRCHi = auchCRCLo[uIndex];
    }
    a.resize(2);
    a[0] = uchCRCLo;
    a[1] = uchCRCHi;
    return a;
}

#ifdef USE_CRC_MODULE

QByteArray BaseSerialComm::verifyCRC16_CCITT(QByteArray buf)
{
    /* Xmodem */
    QByteArray a;
    quint16 crc16Xmodem;
    char * tmpPtr = buf.data();
    const unsigned char* ptr = (const unsigned char* )tmpPtr;
    crc16Xmodem = crc_xmodem(ptr, buf.size());
    a.resize(2);
    a[0] = crc16Xmodem;
    a[1] = crc16Xmodem>>8;
    return a;
}
QByteArray BaseSerialComm::verifyCRC32(QByteArray buf)
{
    QByteArray a;
    quint32 crc32;
    char * tmpPtr = buf.data();
    const unsigned char* ptr = (const unsigned char* )tmpPtr;
    crc32 = crc_32(ptr, buf.size());
    a.resize(4);
    a[0] = crc32;
    a[1] = crc32>>8;
    a[2] = crc32>>16;
    a[3] = crc32>>24;
    return a;
}
QByteArray BaseSerialComm::verifyLRC(QByteArray buf)
{
    QByteArray tmp = QByteArray ::fromHex(buf);
    quint8 uchLRC = verifyADD8(tmp);
    uchLRC = (~uchLRC) + 1;
    QByteArray a;
    a.clear();
    a.append(uchLRC);
    return a = a.toHex().toUpper();;
}
#endif

