#include <QCoreApplication>
#include <QDebug>
#include "TSharePtr.h"
#include <iostream>
#include <string>

class humen
{
public:
    int age;
    std::string hname;

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TSharePtr<int> int1 = new int(10);
    TSharePtr<int> int2 = new int(11);
    TSharePtr<int> int2_1 = int2;
    TSharePtr<float> float1 = new float(10.01);
    TSharePtr<double> double1 = new double(11.324);
    TSharePtr<double> double2 = new double(12.123);

    //Sample for operator *
    TSharePtr<int> foo (new int);
    TSharePtr<int> bar (new int (100));
    *foo = *bar *11;
    qDebug() << "foo " << foo.getCounter() << " * foo is: "  << *foo;

    //Sample for operator ->
    TSharePtr<humen> humen1 = new humen();
    humen1->age=11;
    humen1->hname="test";

    //Sample for reset
    qDebug() << "int1 " << int1.getCounter() << " value is: "  << int1.getValue();
    qDebug() << "int1 " << int1.getCounter() << " Addres is: "  << int1.getAddres();
    //int1.reset();
    int1.reset(new int{43});
    qDebug() << "After Reset int1 " << int1.getCounter() << " value is: "  << int1.getValue();
    qDebug() << "After Reset int1 " << int1.getCounter() << " Addres is: "  << int1.getAddres();


    //Sample for template
    qDebug() << "int2 " << int2.getCounter() << " value is: "  << int2.getValue();
    qDebug() << "int2_1 " << int2_1.getCounter() << " value is: "  << int2_1.getValue();
    qDebug() << "int1 " << int1.getCounter() << " value is: "  << int1.getValue();
    qDebug() << "float1 " << float1.getCounter() << " value is: "  << float1.getValue();
    qDebug() << "float1 " << float1.getCounter() << " Address is: "  << float1.getAddres();
    qDebug() << "double1 " << double1.getCounter() << " value is: "  << double1.getValue();
    qDebug() << "double2 " << double2.getCounter() << " value is: "  << double2.getValue();

    return a.exec();
}
