#ifndef DYNAMICPTR_H
#define DYNAMICPTR_H

#include <iostream>
#include <mutex>

template<typename T>
class Dynamicptr
{

public:
    Dynamicptr(T *pointer)
    {
        counter = new int(1);
        parameter= pointer;
        m_mutex=new std::mutex;
    }


    Dynamicptr(const Dynamicptr &cpyPtr)
    {
        m_mutex=cpyPtr.m_mutex;

        std::lock_guard<std::mutex> lock(*m_mutex);

        this->counter= cpyPtr.counter;

        if (cpyPtr.parameter != nullptr)
        {

            (*counter)++;
        }
    }


    void remove_ptr_cntr()
    {
        std::lock_guard<std::mutex>lock(*m_mutex);

        if(counter != nullptr)
        {

            (*counter)--;
            if (*counter == 0)
            {
                delete counter;
                delete parameter;
                delete m_mutex;

            }
        }
    }

    int getCounter()
    {
        std::lock_guard<std::mutex>lock(*m_mutex);

        if(counter != nullptr)
        {

            return *counter;
        }
        return 0;
    }

    ~Dynamicptr()
    {
        remove_ptr_cntr();
    }



private:

    int *counter;
    T *parameter;
    std::mutex *m_mutex;


};

#endif // DYNAMICPTR_H
