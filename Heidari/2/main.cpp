#include <QCoreApplication>
#include "Intsharedptr.h"
#include <iostream>
#include <memory>

class MyIntPtr {
private:
    static size_t count;
    int * ptrInt = nullptr;
public:
    MyIntPtr(int * ptr)
    {
        ptrInt = ptr;
        ++count;

    }

//*******************************************************//
    MyIntPtr(const MyIntPtr& refPtr)
    {
        ptrInt = refPtr.ptrInt;
        count = refPtr.count;
    }

//*******************************************************//
    ~MyIntPtr()
    {
        count--;
               if (count == 0)
               {
                   delete ptrInt;
               }
    }

//*******************************************************//
    static size_t howMany()
    {
        return count;
    }

//*******************************************************//
    int getValue()
    {
        return * ptrInt;
    }

};
int MyIntPtr::count = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int * input = new int(22);
    MyIntPtr ptr1(input);
    input = nullptr;
    delete input;

    int * input2 = new int(42);
    MyIntPtr ptr2(input2);
    input2 = nullptr;
    delete input2;

    std::cerr <<  "" <<  ptr1.getValue() << std::endl;
    std::cerr <<  "" <<  MyIntPtr::howMany()<< std::endl;
    std::cerr <<  "" <<  ptr2.getValue() << std::endl;
    return a.exec();
}
