#include <iostream>
#include "SharedPointer.h"

//using namespace std;

int main()
{
    int a = 8;

    MySharedPtr mySharedPtr(new int(a));

    mySharedPtr.getRefCountr();
    std::cout << *mySharedPtr << std::endl;


    MySharedPtr mySharedPtr2 = mySharedPtr;
    mySharedPtr.getRefCountr();
    std::cout << *mySharedPtr2 << std::endl;


    {
        MySharedPtr mySharedPtr3 = mySharedPtr;
        mySharedPtr.getRefCountr();
        std::cout << *mySharedPtr3 << std::endl;

    }

    return 0;
}
