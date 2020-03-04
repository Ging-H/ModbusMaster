#ifndef BASESERIALCOMM_H
#define BASESERIALCOMM_H

#include <QComboBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QAbstractItemView>

//#define USE_CRC_MODULE // 使用 CRC校验模块才会使用这个宏
class BaseSerialComm : public QSerialPort,public QSerialPortInfo
{
    Q_OBJECT
public:
    // QSerialPort 只有115200波特率, 为避免直接修改库文件,重写波特率枚举类型
    //
    enum BaudRate {
        Baud1200    = 1200,
        Baud2400    = 2400,
        Baud4800    = 4800,
        Baud9600    = 9600,
        Baud19200   = 19200,
        Baud38400   = 38400,
        Baud57600   = 57600,
        Baud115200  = 115200,
        Baud128000  = 128000,
        Baud256000  = 256000,
        Baud1000000 = 1000000,
        UnknownBaud = -1
    };
    Q_ENUM(BaudRate)

    enum  Terminator{
        NONE        = 0,
        CRLF_0x0D0A = 0x0D0A, // '\r''\n',
        CR_0x0D     = 0x0D,   // '\r',
        LF_0xOA     = 0x0A,   // '\n',
        UnknownTerminator = -1
    };
    Q_ENUM(Terminator)

    enum VerifyStyle{
        AddVerifyItem      = 0,
        ADD8               = 1,
        NADD8              = 2,
        XOR8               = 3,
        CRC_Modbus         = 4,
        CRC_Xmodem         = 5,
        CRC32              = 6,
        LRC                = 7, // Longitudinal Redundancy Check
        UnknownStyle       = -1
    };
    Q_ENUM(VerifyStyle)

    explicit BaseSerialComm(QSerialPort *parent = nullptr);

    static void listVerify      (QComboBox *cbbVerify);
    static void listStopBit     (QComboBox *cbbStopBit);
    static void listBaudRate    (QComboBox *cbbBaud);
    static void listDataBit     (QComboBox *cbbDataBit);
    static void listPortNum     (QComboBox *cbbPortNum);
    static void listTerminator  (QComboBox *cbbTerminator);
    static void listVerifyStyle (QComboBox *cbbVerifyStyle);
    static void searchPort      (QStringList &portList);
    static quint8 verifyADD8    (QByteArray  buf );
    static quint8 verifyXOR8    (QByteArray  buf );
    static QByteArray verifyCRC16   (QByteArray  buf);
    static QByteArray verifyCRC16_CCITT(QByteArray buf);
    static QByteArray verifyCRC32(QByteArray buf);
    static QByteArray verifyLRC( QByteArray buf );
    static bool isHexString(QString src);


//    static void verifyCon?stant  (QByteArray &buf,  qint32 size);
    QByteArray insertVerify(QByteArray &buf, int start, int end, int VerifyStyle);
    qint32 readData   (QByteArray &rxBuffer);
    qint32 writtenData(QString txBuffer);
    void setDTRState(bool set);
    void setRTSState(bool set);
    void insertTerminator(QByteArray &buffer,BaseSerialComm::Terminator terminator);



signals:

public slots:



};

#endif // BASESERIALCOMM_H

