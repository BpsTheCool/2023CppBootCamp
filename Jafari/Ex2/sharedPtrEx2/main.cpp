#include <QCoreApplication>
#include <QtDebug>
#include "MySharedPtr.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MySharedPtr myShPtr; //this definition without argument not allowed!

    MySharedPtr myShPtr1(1);
    {
        {
            MySharedPtr myShPtr2(2);
            myShPtr2.getSharedCounter();
            MySharedPtr myShPtr3(myShPtr2);
            myShPtr2.getSharedCounter();
            myShPtr3.getSharedCounter();
        }
        MySharedPtr myShPtr4(myShPtr1);
        myShPtr1.getSharedCounter();
        myShPtr4.getSharedCounter();
    }
    qDebug()<< "The End ;)";

    return a.exec();
}
