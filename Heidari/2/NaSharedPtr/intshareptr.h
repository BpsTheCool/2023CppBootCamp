#ifndef INTSHAREPTR_H
#define INTSHAREPTR_H
#include <iostream>

class IntSharePtr
{
private:

    int *counter;
    int * ptrInt = nullptr;
    inline void decreaseCounter();
    inline void increaseCounter();
    void clean();

public:
    IntSharePtr(int * ptr);
    IntSharePtr(const IntSharePtr& refPtr);
    IntSharePtr&  operator =(const IntSharePtr& refPtr);
    IntSharePtr(IntSharePtr && movedPtr);

    ~IntSharePtr();
    int getCounter();
    int* getAddres();
    int getValueOfInt();

};

#endif // INTSHAREPTR_H
