#ifndef INTSHAREPTR_H
#define INTSHAREPTR_H


class IntSharePtr
{
private:
    static int counter;
    int * ptrInt = nullptr;
public:
    IntSharePtr(int * ptr);
    IntSharePtr(const IntSharePtr& refPtr);
    ~IntSharePtr();
    static int getCounter();
    int getValueOfInt();

};

#endif // INTSHAREPTR_H
