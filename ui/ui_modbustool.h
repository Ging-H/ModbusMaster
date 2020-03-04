/********************************************************************************
** Form generated from reading UI file 'modbustool.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSTOOL_H
#define UI_MODBUSTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusTool
{
public:
    QAction *actionModbusPro;
    QAction *actionHelp;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QTextEdit *txtMessage;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_4;
    QPushButton *btn03Send;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txt03SlaveAddr;
    QLineEdit *txt03RegAddr;
    QLineEdit *txt03RegNum;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *txt04SlaveAddr;
    QLineEdit *txt04RegAddr;
    QLineEdit *txt04RegNum;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *txt06SlaveAddr;
    QLineEdit *txt06RegAddr;
    QLineEdit *txt06Value;
    QPushButton *btn04Send;
    QPushButton *btn06Send;
    QPushButton *btn10Send;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QLineEdit *txt10SlaveAddr;
    QLineEdit *txt10RegAddr;
    QLineEdit *txt10RegNum;
    QLineEdit *txt10Value;
    QPushButton *btnOtherSend;
    QLineEdit *txtOtherValue;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QRadioButton *robMaster;
    QRadioButton *robSlaver;
    QToolButton *btnSubtract;
    QToolButton *btnPlus;
    QPushButton *btnExpand;
    QGroupBox *QGBSerialConfig;
    QPushButton *btnOpenPort;
    QPushButton *btnRefresh;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lblPortNum;
    QComboBox *cbbPortNum;
    QLabel *lblBaudRate;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QComboBox *cbbDataBit;
    QLabel *lblVerify;
    QComboBox *cbbVerify;
    QLabel *lblStopBit;
    QComboBox *cbbStopBit;
    QToolBar *toolBar;
    QButtonGroup *bgpMSS;

    void setupUi(QMainWindow *ModbusTool)
    {
        if (ModbusTool->objectName().isEmpty())
            ModbusTool->setObjectName(QStringLiteral("ModbusTool"));
        ModbusTool->resize(542, 487);
        actionModbusPro = new QAction(ModbusTool);
        actionModbusPro->setObjectName(QStringLiteral("actionModbusPro"));
        actionHelp = new QAction(ModbusTool);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(ModbusTool);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(524, 442));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        txtMessage = new QTextEdit(groupBox);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));
        sizePolicy.setHeightForWidth(txtMessage->sizePolicy().hasHeightForWidth());
        txtMessage->setSizePolicy(sizePolicy);
        txtMessage->setReadOnly(true);

        gridLayout_5->addWidget(txtMessage, 2, 1, 1, 1);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        sizePolicy.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy);
        groupBox_8->setMinimumSize(QSize(0, 0));
        groupBox_8->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_8);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        btn03Send = new QPushButton(groupBox_8);
        btn03Send->setObjectName(QStringLiteral("btn03Send"));

        gridLayout_4->addWidget(btn03Send, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox_8);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_8);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_8);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        txt03SlaveAddr = new QLineEdit(groupBox_8);
        txt03SlaveAddr->setObjectName(QStringLiteral("txt03SlaveAddr"));

        gridLayout_2->addWidget(txt03SlaveAddr, 1, 0, 1, 1);

        txt03RegAddr = new QLineEdit(groupBox_8);
        txt03RegAddr->setObjectName(QStringLiteral("txt03RegAddr"));

        gridLayout_2->addWidget(txt03RegAddr, 1, 1, 1, 1);

        txt03RegNum = new QLineEdit(groupBox_8);
        txt03RegNum->setObjectName(QStringLiteral("txt03RegNum"));

        gridLayout_2->addWidget(txt03RegNum, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 2, 1, 1);

        txt04SlaveAddr = new QLineEdit(groupBox_8);
        txt04SlaveAddr->setObjectName(QStringLiteral("txt04SlaveAddr"));

        gridLayout_2->addWidget(txt04SlaveAddr, 3, 0, 1, 1);

        txt04RegAddr = new QLineEdit(groupBox_8);
        txt04RegAddr->setObjectName(QStringLiteral("txt04RegAddr"));

        gridLayout_2->addWidget(txt04RegAddr, 3, 1, 1, 1);

        txt04RegNum = new QLineEdit(groupBox_8);
        txt04RegNum->setObjectName(QStringLiteral("txt04RegNum"));

        gridLayout_2->addWidget(txt04RegNum, 3, 2, 1, 1);

        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 4, 0, 1, 1);

        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 4, 1, 1, 1);

        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 4, 2, 1, 1);

        txt06SlaveAddr = new QLineEdit(groupBox_8);
        txt06SlaveAddr->setObjectName(QStringLiteral("txt06SlaveAddr"));

        gridLayout_2->addWidget(txt06SlaveAddr, 5, 0, 1, 1);

        txt06RegAddr = new QLineEdit(groupBox_8);
        txt06RegAddr->setObjectName(QStringLiteral("txt06RegAddr"));

        gridLayout_2->addWidget(txt06RegAddr, 5, 1, 1, 1);

        txt06Value = new QLineEdit(groupBox_8);
        txt06Value->setObjectName(QStringLiteral("txt06Value"));

        gridLayout_2->addWidget(txt06Value, 5, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 1, 3, 1);

        btn04Send = new QPushButton(groupBox_8);
        btn04Send->setObjectName(QStringLiteral("btn04Send"));

        gridLayout_4->addWidget(btn04Send, 1, 0, 1, 1);

        btn06Send = new QPushButton(groupBox_8);
        btn06Send->setObjectName(QStringLiteral("btn06Send"));

        gridLayout_4->addWidget(btn06Send, 2, 0, 1, 1);

        btn10Send = new QPushButton(groupBox_8);
        btn10Send->setObjectName(QStringLiteral("btn10Send"));

        gridLayout_4->addWidget(btn10Send, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(35, 0));
        label_13->setMaximumSize(QSize(35, 16777215));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 0, 2, 1, 1);

        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 0, 3, 1, 1);

        txt10SlaveAddr = new QLineEdit(groupBox_8);
        txt10SlaveAddr->setObjectName(QStringLiteral("txt10SlaveAddr"));
        txt10SlaveAddr->setMinimumSize(QSize(35, 0));
        txt10SlaveAddr->setMaximumSize(QSize(35, 16777215));

        gridLayout_3->addWidget(txt10SlaveAddr, 1, 0, 1, 1);

        txt10RegAddr = new QLineEdit(groupBox_8);
        txt10RegAddr->setObjectName(QStringLiteral("txt10RegAddr"));

        gridLayout_3->addWidget(txt10RegAddr, 1, 1, 1, 1);

        txt10RegNum = new QLineEdit(groupBox_8);
        txt10RegNum->setObjectName(QStringLiteral("txt10RegNum"));

        gridLayout_3->addWidget(txt10RegNum, 1, 2, 1, 1);

        txt10Value = new QLineEdit(groupBox_8);
        txt10Value->setObjectName(QStringLiteral("txt10Value"));

        gridLayout_3->addWidget(txt10Value, 1, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 3, 1, 1, 1);

        btnOtherSend = new QPushButton(groupBox_8);
        btnOtherSend->setObjectName(QStringLiteral("btnOtherSend"));

        gridLayout_4->addWidget(btnOtherSend, 4, 0, 1, 1);

        txtOtherValue = new QLineEdit(groupBox_8);
        txtOtherValue->setObjectName(QStringLiteral("txtOtherValue"));

        gridLayout_4->addWidget(txtOtherValue, 4, 1, 1, 1);

        btn10Send->raise();
        txt06Value->raise();
        txt06RegAddr->raise();
        txt06SlaveAddr->raise();
        btn06Send->raise();
        label_9->raise();
        label_11->raise();
        label_12->raise();
        label_9->raise();
        label_11->raise();
        txt04RegNum->raise();
        btn04Send->raise();
        txt04RegAddr->raise();
        txt04SlaveAddr->raise();
        label_7->raise();
        label_4->raise();
        label_8->raise();
        txt03RegNum->raise();
        txt03SlaveAddr->raise();
        btn03Send->raise();
        txt03RegAddr->raise();
        label_3->raise();
        label->raise();
        label_2->raise();

        gridLayout_5->addWidget(groupBox_8, 0, 1, 2, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 57, 91, 18));
        checkBox->setChecked(true);
        robMaster = new QRadioButton(groupBox_2);
        bgpMSS = new QButtonGroup(ModbusTool);
        bgpMSS->setObjectName(QStringLiteral("bgpMSS"));
        bgpMSS->addButton(robMaster);
        robMaster->setObjectName(QStringLiteral("robMaster"));
        robMaster->setGeometry(QRect(10, 81, 43, 18));
        robMaster->setChecked(true);
        robSlaver = new QRadioButton(groupBox_2);
        bgpMSS->addButton(robSlaver);
        robSlaver->setObjectName(QStringLiteral("robSlaver"));
        robSlaver->setGeometry(QRect(10, 105, 55, 18));
        btnSubtract = new QToolButton(groupBox_2);
        btnSubtract->setObjectName(QStringLiteral("btnSubtract"));
        btnSubtract->setGeometry(QRect(118, 29, 26, 19));
        btnPlus = new QToolButton(groupBox_2);
        btnPlus->setObjectName(QStringLiteral("btnPlus"));
        btnPlus->setGeometry(QRect(88, 29, 26, 19));
        btnExpand = new QPushButton(groupBox_2);
        btnExpand->setObjectName(QStringLiteral("btnExpand"));
        btnExpand->setGeometry(QRect(12, 29, 72, 20));

        gridLayout_5->addWidget(groupBox_2, 1, 0, 2, 1);

        QGBSerialConfig = new QGroupBox(groupBox);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy1);
        QGBSerialConfig->setMinimumSize(QSize(171, 211));
        QGBSerialConfig->setMaximumSize(QSize(171, 211));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setEnabled(true);
        btnOpenPort->setGeometry(QRect(69, 165, 91, 31));
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/action/action/centrejust.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/action/action/process-stop.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon);
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);
        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(11, 165, 51, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/action/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon1);
        widget = new QWidget(QGBSerialConfig);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 21, 146, 136));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblPortNum = new QLabel(widget);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout->addWidget(lblPortNum, 0, 0, 1, 1);

        cbbPortNum = new QComboBox(widget);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy2);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout->addWidget(cbbPortNum, 0, 1, 1, 1);

        lblBaudRate = new QLabel(widget);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbBaud = new QComboBox(widget);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(widget);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout->addWidget(lblDataBit, 2, 0, 1, 1);

        cbbDataBit = new QComboBox(widget);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblVerify = new QLabel(widget);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout->addWidget(lblVerify, 3, 0, 1, 1);

        cbbVerify = new QComboBox(widget);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbVerify, 3, 1, 1, 1);

        lblStopBit = new QLabel(widget);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout->addWidget(lblStopBit, 4, 0, 1, 1);

        cbbStopBit = new QComboBox(widget);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbStopBit, 4, 1, 1, 1);


        gridLayout_5->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        groupBox_8->raise();
        QGBSerialConfig->raise();
        groupBox_2->raise();
        txtOtherValue->raise();
        btnOtherSend->raise();
        txtMessage->raise();

        horizontalLayout->addWidget(groupBox);

        ModbusTool->setCentralWidget(centralWidget);
        toolBar = new QToolBar(ModbusTool);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ModbusTool->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(cbbPortNum, cbbBaud);
        QWidget::setTabOrder(cbbBaud, cbbDataBit);
        QWidget::setTabOrder(cbbDataBit, cbbVerify);
        QWidget::setTabOrder(cbbVerify, cbbStopBit);
        QWidget::setTabOrder(cbbStopBit, btnRefresh);
        QWidget::setTabOrder(btnRefresh, btnOpenPort);
        QWidget::setTabOrder(btnOpenPort, btnExpand);
        QWidget::setTabOrder(btnExpand, btnPlus);
        QWidget::setTabOrder(btnPlus, btnSubtract);
        QWidget::setTabOrder(btnSubtract, checkBox);
        QWidget::setTabOrder(checkBox, robMaster);
        QWidget::setTabOrder(robMaster, robSlaver);
        QWidget::setTabOrder(robSlaver, txt10SlaveAddr);
        QWidget::setTabOrder(txt10SlaveAddr, txt10RegAddr);
        QWidget::setTabOrder(txt10RegAddr, txt10RegNum);
        QWidget::setTabOrder(txt10RegNum, txt10Value);
        QWidget::setTabOrder(txt10Value, btn10Send);

        toolBar->addAction(actionHelp);
        toolBar->addAction(actionModbusPro);

        retranslateUi(ModbusTool);

        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(ModbusTool);
    } // setupUi

    void retranslateUi(QMainWindow *ModbusTool)
    {
        ModbusTool->setWindowTitle(QApplication::translate("ModbusTool", "ModbusTool", Q_NULLPTR));
        actionModbusPro->setText(QApplication::translate("ModbusTool", "Modbus\345\215\217\350\256\256", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("ModbusTool", "\345\270\256\345\212\251\350\257\264\346\230\216", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_8->setTitle(QApplication::translate("ModbusTool", "\345\270\270\347\224\250\346\214\207\344\273\244", Q_NULLPTR));
        btn03Send->setText(QApplication::translate("ModbusTool", "03H", Q_NULLPTR));
        label->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_8->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_7->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", Q_NULLPTR));
        label_9->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_11->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_12->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\200\274", Q_NULLPTR));
        btn04Send->setText(QApplication::translate("ModbusTool", "04H", Q_NULLPTR));
        btn06Send->setText(QApplication::translate("ModbusTool", "06H", Q_NULLPTR));
        btn10Send->setText(QApplication::translate("ModbusTool", "10H", Q_NULLPTR));
        label_13->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_15->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_16->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", Q_NULLPTR));
        label_14->setText(QApplication::translate("ModbusTool", "\346\225\260\346\215\256\345\200\274", Q_NULLPTR));
        btnOtherSend->setText(QApplication::translate("ModbusTool", "\345\205\266\344\273\226\346\214\207\344\273\244", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ModbusTool", "Config", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ModbusTool", "\345\270\246CRC\346\240\241\351\252\214\347\240\201", Q_NULLPTR));
        robMaster->setText(QApplication::translate("ModbusTool", "RTU", Q_NULLPTR));
        robSlaver->setText(QApplication::translate("ModbusTool", "ASCII", Q_NULLPTR));
        btnSubtract->setText(QApplication::translate("ModbusTool", "-", Q_NULLPTR));
        btnPlus->setText(QApplication::translate("ModbusTool", "+", Q_NULLPTR));
        btnExpand->setText(QApplication::translate("ModbusTool", "\346\250\241\346\213\237\350\256\276\345\244\207", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("ModbusTool", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("ModbusTool", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("ModbusTool", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("ModbusTool", "\345\210\267\346\226\260", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("ModbusTool", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("ModbusTool", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("ModbusTool", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("ModbusTool", "\346\240\241\351\252\214", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("ModbusTool", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("ModbusTool", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModbusTool: public Ui_ModbusTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSTOOL_H