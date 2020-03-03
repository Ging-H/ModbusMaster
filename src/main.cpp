#include "modbustool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModbusTool w;
    w.show();

    return a.exec();
}
