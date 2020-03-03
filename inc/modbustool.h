#ifndef MODBUSTOOL_H
#define MODBUSTOOL_H

#include <QMainWindow>

namespace Ui {
class ModbusTool;
}

class ModbusTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModbusTool(QWidget *parent = 0);
    ~ModbusTool();

private:
    Ui::ModbusTool *ui;
};

#endif // MODBUSTOOL_H
