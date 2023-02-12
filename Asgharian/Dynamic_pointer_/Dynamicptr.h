#ifndef DYNAMICPTR_H
#define DYNAMICPTR_H

#include <iostream>

class Dynamicptr
{

public:
    Dynamicptr(int *pointer);
    Dynamicptr(const Dynamicptr &cpyPtr);

    void remove_ptr_cntr();
    int getCounter();

    ~Dynamicptr();


private:

    int *counter;
    int *parameter;


};

#endif // DYNAMICPTR_H
