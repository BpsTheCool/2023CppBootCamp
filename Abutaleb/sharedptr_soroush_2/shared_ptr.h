#ifndef SHARED_PTR_H
#define SHARED_PTR_H

int test;
#include<atomic>
#include<mutex>

template<typename T>
class Shared_ptr
{
    int* m_counter;
    T* smartpoiter;
    std::mutex* m_lock;
//    std::unique_lock<std::mutex> m_u_l;

public:
    Shared_ptr( T* pointer=nullptr)
        : smartpoiter(pointer)
    {
        m_counter = new int (0);
        m_lock = new std::mutex;
        m_lock->lock();
        (*m_counter)++;
        m_lock->unlock();
    }

    Shared_ptr(Shared_ptr& copy)
    {
        m_lock = copy.m_lock;
        smartpoiter=copy.smartpoiter;
        m_counter = copy.m_counter;
        m_lock->lock();
        (*m_counter)++;
        m_lock->unlock();
    }

    Shared_ptr(Shared_ptr&& move)
    {
        smartpoiter=std::move(move.smartpoiter);
    }

    void operator=(Shared_ptr& copy)
    {
        m_lock = copy.m_lock;
        smartpoiter=copy.smartpoiter;
        m_counter = copy.m_counter;
        m_lock->lock();
        (*m_counter)++;
        m_lock->unlock();
    }

    T* operator->()
    {
        return smartpoiter;
    }

    T operator*()
    {
        return *smartpoiter;
    }

    bool operator==(void* x)
    {
        if(smartpoiter==x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void reset()
    {
        smartpoiter=nullptr;
    }

    ~Shared_ptr()
    {
        m_lock->lock();
        (*m_counter)--;
        m_lock->unlock();
        if(*m_counter==0)
        {
            delete smartpoiter;
            delete m_counter;
        }
    }

    int use_count()
    {
        test=*m_counter;
        return *m_counter;
    }
};

#endif // SHARED_PTR_H
