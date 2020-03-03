#include "modbustool.h"
#include "ui_modbustool.h"

ModbusTool::ModbusTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModbusTool)
{
    ui->setupUi(this);
}

ModbusTool::~ModbusTool()
{
    delete ui;
}
