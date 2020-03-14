#ifndef MODBUSTOOL_H
#define MODBUSTOOL_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTime>


namespace Ui {
class ModbusTool;
}

class ModbusTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModbusTool(QWidget *parent = 0);
    ~ModbusTool();

    /* 接收数据帧 */
    struct {
        quint8 slaveAddr; // 从设备地址
        quint8 cmd;       // 指令
        quint16 regAddr;  // 寄存器地址
        quint16 regNum;   // 寄存器数量
        quint8  byteNum;  // 字节数
        quint8  data[256];// 数据
        quint16  CRC; // 校验码
    }rxFrame;
    enum ProtocalMode{
        RTU,
        ASCII,
    };
    enum ModbusCMD{
        cmd01H = 0x01,
        cmd02H = 0x02,
        cmd03H = 0x03,
        cmd04H = 0x04,
        cmd05H = 0x05,
        cmd06H = 0x06,
        cmd0FH = 0x07,
        cmd10H = 0x10,
        cmd14H = 0x14,
        cmd15H = 0x15,
        cmd16H = 0x16,
        cmd17H = 0x17,
        cmd2BH = 0x2B,
    };


    QByteArray rxDataBuf;
    int  rxCurrSize;

    void initComboBox_Config();
    void configPort();
    void initPlot();
    void setLineEditInputType();

    quint16 crc16_modbus_calc(quint8 *data, quint32 length);
    quint8 verifyLRC(quint8 *data, quint32 length);
    void sendFrame(QByteArray txbuf);
    void frameProtocal(QByteArray rxBuf ,ProtocalMode mode);
    void insertLogAtTime(QString msg);


signals:
    void signal_writtenData(QByteArray txBuf);

public slots :
    void slots_RxCallback();

    void slots_errorHandler(QSerialPort::SerialPortError error);

    void slots_waitForCRC();


private slots:
    void on_btnRefresh_clicked();

    void on_btnOpenPort_clicked(bool checked);

    void on_txt03SlaveAddr_textChanged(const QString &arg1);

    void on_txt03RegAddr_textChanged(const QString &arg1);

    void on_txt03RegNum_textChanged(const QString &arg1);

    void on_txt04SlaveAddr_textChanged(const QString &arg1);

    void on_txt04RegAddr_textChanged(const QString &arg1);

    void on_txt04RegNum_textChanged(const QString &arg1);

    void on_txt06SlaveAddr_textChanged(const QString &arg1);

    void on_txt06RegAddr_textChanged(const QString &arg1);

    void on_txt06Value_textChanged(const QString &arg1);

    void on_txt10SlaveAddr_textChanged(const QString &arg1);

    void on_txt10RegAddr_textChanged(const QString &arg1);

    void on_txt10RegNum_textChanged(const QString &arg1);

    void on_btnOtherSend_clicked();

    void on_btn03Send_clicked();

    void on_btn04Send_clicked();

    void on_btn06Send_clicked();

    void on_btn10Send_clicked();

private:
    Ui::ModbusTool *ui;

    BaseSerialComm *currentPort;   // 端口号

};

#endif // MODBUSTOOL_H

