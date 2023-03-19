#ifndef SHARED_PTR_H
#define SHARED_PTR_H

template<typename T>
class Shared_ptr
{
    int* m_counter;
    T* smartpoiter;
public:
    Shared_ptr( T* pointer)
        : smartpoiter(pointer)
    {
        m_counter = new int (0);
        (*m_counter)++;
    };

    Shared_ptr(Shared_ptr& copy)
    {
        m_counter = copy.m_counter;
        (*m_counter)++;
    };

    void operator=(Shared_ptr& copy)
    {
        m_counter = copy.m_counter;
        (*m_counter)++;
    };

    ~Shared_ptr()
    {
        (*m_counter)--;
        if(*m_counter==0)
        {
            delete smartpoiter;
            delete m_counter;
        }
    }

    int use_count()
    {
        return *m_counter;
    };
};

#endif // SHARED_PTR_H
