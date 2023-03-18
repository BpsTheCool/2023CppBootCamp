#include <QCoreApplication>
#include <QDebug>
#include "TSharePtr.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TSharePtr<int> int1 = new int(10);
    TSharePtr<int> int2 = new int(11);
    TSharePtr<int> int2_1 = int2;
    TSharePtr<float> float1 = new float(10.01);
    TSharePtr<double> double1 = new double(11.324);
    TSharePtr<double> double2 = new double(12.123);

    qDebug() << "int1 " << int1.getCounter() << " value is: "  << int1.getValue();
    qDebug() << "int2 " << int2.getCounter() << " value is: "  << int2.getValue();
    qDebug() << "int2_1 " << int2_1.getCounter() << " value is: "  << int2_1.getValue();
    qDebug() << "int1 " << int1.getCounter() << " value is: "  << int1.getValue();
    qDebug() << "float1 " << float1.getCounter() << " value is: "  << float1.getValue();
    qDebug() << "double1 " << double1.getCounter() << " value is: "  << double1.getValue();
    qDebug() << "double2 " << double2.getCounter() << " value is: "  << double2.getValue();

    return a.exec();
}
