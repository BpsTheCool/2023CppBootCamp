#ifndef SHAREDPTR_H
#define SHAREDPTR_H


class Sharedptr
{
    int *m_a;
    //Sharedptr m_ptr;
    int* m_count;
public:
    Sharedptr(int *a);
    Sharedptr(Sharedptr &a);
    ~Sharedptr();
    void printcount();
    int getm_a();
    //static void setCount(int newCount);
};

#endif // SHAREDPTR_H
