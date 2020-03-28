#include "modbusmaster.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModbusMaster w;
    w.show();

    return a.exec();
}
