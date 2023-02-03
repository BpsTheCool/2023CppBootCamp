#include "intshareptr.h"
int IntSharePtr::counter = 0;
int IntSharePtr::getCounter()
{
    return counter;
}

int IntSharePtr::getValueOfInt()
{
    return *ptrInt;
}

IntSharePtr::IntSharePtr(int * ptr)
{
    ptrInt = ptr;
    ++counter;
}

IntSharePtr::IntSharePtr(const IntSharePtr& refPtr)
{
    ptrInt = refPtr.ptrInt;
    counter = refPtr.counter;
}

IntSharePtr::~IntSharePtr()
{
    counter--;
           if (counter == 0)
           {
               delete ptrInt;
           }
}

