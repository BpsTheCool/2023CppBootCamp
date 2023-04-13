#include <QCoreApplication>
#include <QDebug>
#include "TSafeSharePtr.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TSafeSharePtr<int> int1 = new int(10);
      TSafeSharePtr<int> inta = int1;
    std::thread th1([int1]()
    {
        for(int i=0;i<10000;i++)
        {
            TSafeSharePtr<int> intT1 = int1;
            if(i==9999)
                qDebug() << "intT1 getCounter " << intT1.getCounter() << " value is: "  << intT1.getValue();
        }

    });
    std::thread th2([int1]()
    {
        for(int i=0;i<10000;i++)
        {
             TSafeSharePtr<int> intT3 = int1;
            if(i==9999)
               qDebug() << "intT3 getCounter " << intT3.getCounter() << " value is: "  << intT3.getValue();
        }
    });



    qDebug() << "int1 getCounter " << int1.getCounter() << " value is: "  << int1.getValue();
    th1.join();
    th2.join();


    return a.exec();
}
