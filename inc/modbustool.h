#ifndef MODBUSTOOL_H
#define MODBUSTOOL_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTime>
#include <QDebug>
#include <QTimer>
#include <QSettings>
#include <QCloseEvent>
#include <QScrollArea>
#include <QSpinBox>

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
    struct RxProtocal{
        quint8 slaveAddr; // 从设备地址
        quint8 cmd;       // 指令
        quint16 regAddr;  // 寄存器地址
        quint16 regNum;   // 寄存器数量
        quint8  byteNum;  // 字节数
        quint8  data[256];// 数据
        quint16  verify; // 校验码
    }rxFrame;
    struct Bit_Field
    {
        quint8  bit0:1;
        quint8  bit1:1;
        quint8  bit2:1;
        quint8  bit3:1;
        quint8  bit4:1;
        quint8  bit5:1;
        quint8  bit6:1;
        quint8  bit7:1;
    };
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
        cmd0FH = 0x0F,
        cmd10H = 0x10,
    };
    enum ExceptionCode{
        Exception01 = 1,
        Exception02 ,
        Exception03 ,
        Exception04 ,
        Exception05 ,
        Exception06 ,
        Exception07 ,
        Exception08 ,
    };



    QByteArray rxDataBuf;
    int  rxCurrSize;
    bool  isExpand = false;
    int   Count = 0;
    int   lastCount = 0;
    int   currentCount = 0;
    bool  firstStart = true;

    void initComboBox_Config();
    void configPort();
    void initPlot();
    void setLineEditInputType();

    quint16 crc16_modbus_calc(quint8 *data, quint32 length);
    quint8 verifyLRC(quint8 *data, quint32 length);
    void sendFrame(QByteArray txbuf);
    void frameProtocal(QByteArray rxBuf ,ProtocalMode mode);
    void insertLogAtTime(QString msg);
    void getInitTxt();
    void exceptionHandle(ExceptionCode exception );
    void iniSpb(QSpinBox *spb);
    void iniBtn(QPushButton *btn);
    void iniTxt(QLineEdit *txt);
    void initMultiwidget();
    void addWidgetGoup(int count);
    void readMultiWidget();


signals:
    void signal_writtenData(QByteArray txBuf);

    void signal_cmd01HProtocal();

    void signal_cmd03HProtocal();

    void signal_cmd05HProtocal();

    void signal_cmd06HProtocal();

    void signal_cmd10HProtocal();

public slots :
    void slots_RxCallback();

    void slots_errorHandler(QSerialPort::SerialPortError error);

    void slots_waitForCRC();

    void slots_cmd01HProtocal();

    void slots_cmd03HProtocal();

    void slots_cmd05HProtocal();

    void slots_cmd06HProtocal();

    void slots_cmd10HProtocal();

    void slots_showBtnRightClickMenu(const QPoint &pos);

    void slots_clicktoSend();

    void slots_singleShot();



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


    void on_btnExpand_clicked();

    void on_actionRename_triggered();

    void on_btnPlus_clicked();

    void on_btnSubtract_clicked();

    void on_pushButton_clicked(bool checked);

    void on_actionModbusPro_triggered();

protected :
    void closeEvent(QCloseEvent *event);

private:
    Ui::ModbusTool *ui;
    QMenu *btnMenu;
    BaseSerialComm *currentPort;   // 端口号
    QVector<QCheckBox *> multiCkb;
    QVector<QSpinBox *> multiSpb;
    QVector<QPushButton *> multiBtn;
    QVector<QLineEdit *> multiTxt;

};

#endif // MODBUSTOOL_H

