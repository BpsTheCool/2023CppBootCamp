#include <QCoreApplication>
#include <iostream>
#include <memory>
#include "intshareptr.h"

void movePointer(IntSharePtr &&test)
{
    IntSharePtr moved(std::move(test));
   // IntSharePtr moved((test));

    std::cerr << "moved use_count: " << moved.getCounter() << " test  use_count: " <<  test.getCounter() << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    int * input = new int(22);
    IntSharePtr ptr1(input);
    IntSharePtr pt = ptr1;
    input = nullptr;
    delete input;

    int * input2 = new int(42);
    IntSharePtr ptr2(input2);
     IntSharePtr pt2 = ptr2;
     {
       IntSharePtr pt3 = pt2;
       std::cerr <<  " in scope" <<  ptr2.getCounter()<< std::endl;
       std::cerr <<  "  &pt3 " <<  &pt3 <<  " pt3  " <<  pt3.getAddres() <<std::endl;
     }
    input2 = nullptr;
    delete input2;

     std::cerr <<  "  &ptr2 " <<  &ptr2 <<  " ptr2 " <<  ptr2.getAddres() <<std::endl;
     std::cerr <<  "  &pt2 " <<  &pt2 <<   " pt2  " <<  pt2.getAddres() <<std::endl;


    std::cerr <<  "" <<  ptr1.getValueOfInt() << std::endl;
    std::cerr <<  "" <<  ptr1.getCounter()<< std::endl;
    std::cerr <<  "" <<  ptr2.getValueOfInt() << std::endl;
    std::cerr <<  "" <<  ptr2.getCounter()<< std::endl;

    //Moved
    int * testMoved = new int(42);
    IntSharePtr test =  std::move(testMoved);
    movePointer(std::move(test));

    return a.exec();
}
