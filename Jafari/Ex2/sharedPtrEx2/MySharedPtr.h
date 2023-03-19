#ifndef MYSHAREDPTR_H
#define MYSHAREDPTR_H


class MySharedPtr
{
    int *m_SharedPtr;
    int *m_SharedCounter;

public:

    MySharedPtr();
    MySharedPtr(int shP);

    ~MySharedPtr();

    MySharedPtr(MySharedPtr &copy);

    void getSharedCounter() const;
    void plusSharedCounter();
};

#endif // MYSHAREDPTR_H
