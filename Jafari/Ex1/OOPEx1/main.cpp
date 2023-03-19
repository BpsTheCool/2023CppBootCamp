#include <QCoreApplication>
#include <QDebug>

//#include "includes/InterfaceDevice.h"
#include "includes/Flash.h"
#include "includes/HDDex.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<< "Hello ...!";

    Flash flash1(100, false);
    HDDex hdd1(1024, false);
    Flash flash2(30, true);
    HDDex hdd2(128, true);

    qDebug()<< "Flash storage: "<< flash1.getStorage();
    flash1.read();
    flash1.edject(true);
    flash1.write();

    qDebug()<< "HDD storage: "<< hdd1.getStorage();
    hdd1.edject(true);
    hdd1.read();
    hdd1.edject(false);
    hdd1.write();

    return a.exec();
}
