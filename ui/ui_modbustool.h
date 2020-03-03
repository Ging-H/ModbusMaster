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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusTool
{
public:
    QAction *actionModbusPro;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGroupBox *QGBSerialConfig;
    QPushButton *btnOpenPort;
    QWidget *formLayoutWidget;
    QGridLayout *commParam;
    QLabel *lblVerify;
    QComboBox *cbbDataBit;
    QLabel *lblPortNum;
    QLabel *lblStopBit;
    QLabel *lblBaudRate;
    QComboBox *cbbPortNum;
    QComboBox *cbbVerify;
    QComboBox *cbbStopBit;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QPushButton *btnRefresh;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_6;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_12;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_6;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QLabel *label_15;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_14;
    QLabel *label_13;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_16;
    QLabel *label_16;
    QLineEdit *lineEdit_13;
    QLabel *label_14;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit_17;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QPushButton *pushButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QCheckBox *checkBox;
    QRadioButton *robMaster;
    QRadioButton *robSlaver;
    QToolBar *toolBar;
    QButtonGroup *bgpMSSelect;

    void setupUi(QMainWindow *ModbusTool)
    {
        if (ModbusTool->objectName().isEmpty())
            ModbusTool->setObjectName(QStringLiteral("ModbusTool"));
        ModbusTool->resize(540, 464);
        actionModbusPro = new QAction(ModbusTool);
        actionModbusPro->setObjectName(QStringLiteral("actionModbusPro"));
        actionHelp = new QAction(ModbusTool);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(ModbusTool);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(534, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        QGBSerialConfig = new QGroupBox(groupBox);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
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
        formLayoutWidget = new QWidget(QGBSerialConfig);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 151, 136));
        commParam = new QGridLayout(formLayoutWidget);
        commParam->setSpacing(6);
        commParam->setContentsMargins(11, 11, 11, 11);
        commParam->setObjectName(QStringLiteral("commParam"));
        commParam->setContentsMargins(0, 0, 0, 0);
        lblVerify = new QLabel(formLayoutWidget);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        commParam->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(formLayoutWidget);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        commParam->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(formLayoutWidget);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        commParam->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(formLayoutWidget);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        commParam->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(formLayoutWidget);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        commParam->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(formLayoutWidget);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy2);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        commParam->addWidget(cbbPortNum, 0, 1, 1, 1);

        cbbVerify = new QComboBox(formLayoutWidget);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        commParam->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(formLayoutWidget);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        commParam->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(formLayoutWidget);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        commParam->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(formLayoutWidget);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        commParam->addWidget(lblDataBit, 2, 0, 1, 1);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(11, 165, 51, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/action/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon1);

        gridLayout->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy3);
        groupBox_8->setMinimumSize(QSize(0, 0));
        groupBox_8->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(6, 6, 6, 6);
        groupBox_5 = new QGroupBox(groupBox_8);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_6 = new QPushButton(groupBox_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_5->addWidget(pushButton_6, 0, 0, 2, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 0, 2, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 0, 3, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox_5);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_5->addWidget(lineEdit_9, 1, 1, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox_5);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_5->addWidget(lineEdit_10, 1, 2, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox_5);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout_5->addWidget(lineEdit_12, 1, 3, 1, 1);


        gridLayout_8->addWidget(groupBox_5, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_8);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_4->addWidget(pushButton_3, 0, 0, 2, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 0, 4, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_4->addWidget(lineEdit_2, 1, 2, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_4->addWidget(lineEdit_3, 1, 3, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_4->addWidget(lineEdit_5, 1, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_8);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_3->addWidget(pushButton_5, 0, 0, 2, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 4, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_3->addWidget(lineEdit_7, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_3->addWidget(lineEdit_4, 1, 2, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox_4);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_3->addWidget(lineEdit_8, 1, 3, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_3->addWidget(lineEdit_6, 1, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_8);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_6->addWidget(label_15, 0, 2, 1, 1);

        lineEdit_15 = new QLineEdit(groupBox_6);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout_6->addWidget(lineEdit_15, 1, 4, 1, 1);

        lineEdit_14 = new QLineEdit(groupBox_6);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        gridLayout_6->addWidget(lineEdit_14, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(35, 0));
        label_13->setMaximumSize(QSize(35, 16777215));

        gridLayout_6->addWidget(label_13, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(groupBox_6);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_6->addWidget(pushButton_7, 0, 0, 2, 1);

        lineEdit_16 = new QLineEdit(groupBox_6);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        gridLayout_6->addWidget(lineEdit_16, 1, 3, 1, 1);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_6->addWidget(label_16, 0, 3, 1, 1);

        lineEdit_13 = new QLineEdit(groupBox_6);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setMinimumSize(QSize(35, 0));
        lineEdit_13->setMaximumSize(QSize(35, 16777215));

        gridLayout_6->addWidget(lineEdit_13, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_6->addWidget(label_14, 0, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_6, 3, 0, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_8);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout = new QHBoxLayout(groupBox_7);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(groupBox_7);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        lineEdit_17 = new QLineEdit(groupBox_7);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));

        horizontalLayout->addWidget(lineEdit_17);


        gridLayout_8->addWidget(groupBox_7, 4, 0, 1, 1);


        gridLayout->addWidget(groupBox_8, 0, 1, 5, 1);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 5, 0, 1, 2);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(groupBox_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        splitter->addWidget(pushButton_2);
        toolButton = new QToolButton(splitter);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        splitter->addWidget(toolButton);
        toolButton_2 = new QToolButton(splitter);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        splitter->addWidget(toolButton_2);

        verticalLayout->addWidget(splitter);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        robMaster = new QRadioButton(groupBox_2);
        bgpMSSelect = new QButtonGroup(ModbusTool);
        bgpMSSelect->setObjectName(QStringLiteral("bgpMSSelect"));
        bgpMSSelect->addButton(robMaster);
        robMaster->setObjectName(QStringLiteral("robMaster"));
        robMaster->setChecked(true);

        verticalLayout->addWidget(robMaster);

        robSlaver = new QRadioButton(groupBox_2);
        bgpMSSelect->addButton(robSlaver);
        robSlaver->setObjectName(QStringLiteral("robSlaver"));

        verticalLayout->addWidget(robSlaver);


        gridLayout->addWidget(groupBox_2, 3, 0, 1, 1);

        groupBox_8->raise();
        textEdit->raise();
        QGBSerialConfig->raise();
        groupBox_2->raise();

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        ModbusTool->setCentralWidget(centralWidget);
        toolBar = new QToolBar(ModbusTool);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ModbusTool->addToolBar(Qt::TopToolBarArea, toolBar);

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
        QGBSerialConfig->setTitle(QApplication::translate("ModbusTool", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("ModbusTool", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("ModbusTool", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("ModbusTool", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("ModbusTool", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("ModbusTool", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("ModbusTool", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("ModbusTool", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("ModbusTool", "\345\210\267\346\226\260", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("ModbusTool", "\345\270\270\347\224\250\346\214\207\344\273\244", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        pushButton_6->setText(QApplication::translate("ModbusTool", "06H", Q_NULLPTR));
        label_9->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_11->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_12->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\200\274", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        pushButton_3->setText(QApplication::translate("ModbusTool", "03H", Q_NULLPTR));
        label->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("ModbusTool", "\346\225\260\346\215\256\345\200\274", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        pushButton_5->setText(QApplication::translate("ModbusTool", "04H", Q_NULLPTR));
        label_4->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        label_8->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_7->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("ModbusTool", "\346\225\260\346\215\256\345\200\274", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        label_15->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_13->setText(QApplication::translate("ModbusTool", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("ModbusTool", "10H", Q_NULLPTR));
        label_16->setText(QApplication::translate("ModbusTool", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", Q_NULLPTR));
        label_14->setText(QApplication::translate("ModbusTool", "\346\225\260\346\215\256\345\200\274", Q_NULLPTR));
        groupBox_7->setTitle(QString());
        pushButton->setText(QApplication::translate("ModbusTool", "\345\205\266\344\273\226\346\214\207\344\273\244", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ModbusTool", "Config", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ModbusTool", "\346\250\241\346\213\237\350\256\276\345\244\207", Q_NULLPTR));
        toolButton->setText(QApplication::translate("ModbusTool", "+", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("ModbusTool", "-", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ModbusTool", "\345\270\246CRC\346\240\241\351\252\214\347\240\201", Q_NULLPTR));
        robMaster->setText(QApplication::translate("ModbusTool", "RTU", Q_NULLPTR));
        robSlaver->setText(QApplication::translate("ModbusTool", "ASCII", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("ModbusTool", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModbusTool: public Ui_ModbusTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSTOOL_H
