#ifndef SHAREDPTR_H
#define SHAREDPTR_H


class Sharedptr
{
    int *m_a;
    static inline int m_count=0;
public:
    Sharedptr(int *a);
    Sharedptr(Sharedptr &a);
    ~Sharedptr();
    void printcount();
    int getm_a();
    //static void setCount(int newCount);
};

#endif // SHAREDPTR_H
