#ifndef MODBUSTOOL_H
#define MODBUSTOOL_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>



namespace Ui {
class ModbusTool;
}

class ModbusTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModbusTool(QWidget *parent = 0);
    ~ModbusTool();

    QByteArray rxDataBuf;
    qint8 txSlaveAddr;
    qint8 txRegAddr;
    qint8 txRegNum;
    qint8 txRegValue;

    void initComboBox_Config();
    void configPort();
    void initPlot();
    void setLineEditInputType();

signals:

public slots :
    void slots_RxCallback();
    void slots_errorHandler(QSerialPort::SerialPortError error);
//    void slots_getRxBuf();

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

private:
    Ui::ModbusTool *ui;
    BaseSerialComm *currentPort;   // 端口号

};

#endif // MODBUSTOOL_H
