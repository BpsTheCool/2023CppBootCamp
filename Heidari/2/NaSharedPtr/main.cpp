#include <QCoreApplication>
#include <iostream>
#include <memory>
#include "intshareptr.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    int * input = new int(22);
    IntSharePtr ptr1(input);
    input = nullptr;
    delete input;

    int * input2 = new int(42);
    IntSharePtr ptr2(input2);
    input2 = nullptr;
    delete input2;

    std::cerr <<  "" <<  ptr1.getValueOfInt() << std::endl;
    std::cerr <<  "" <<  IntSharePtr::getCounter()<< std::endl;
    std::cerr <<  "" <<  ptr2.getValueOfInt() << std::endl;

    return a.exec();
}
