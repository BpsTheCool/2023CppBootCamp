#ifndef INTSHAREDPTR_H
#define INTSHAREDPTR_H


class IntSharedPtr
{
private:
    static int counter  ;

public:
    IntSharedPtr();
    ~IntSharedPtr();

    static int getCounter();
};

#endif // INTSHAREDPTR_H
