#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <set>
#include <QDebug>

class shared_pointer{
    int *m_object;
    int *m_counter;
public:
    shared_pointer();
    shared_pointer(int* new_ptr);
    shared_pointer(shared_pointer &copy);
    shared_pointer(shared_pointer &&moved);
    void operator = (int* new_ptr);
    void operator = (shared_pointer &copy);
    void operator = (shared_pointer &&moved);
    void reset(int* new_ptr);
    int& operator *();
    int* getObject();
    int* getCounter();
    void setNull();
    int countPointers();
    ~shared_pointer();
};

#endif // SMARTPOINTER_H
