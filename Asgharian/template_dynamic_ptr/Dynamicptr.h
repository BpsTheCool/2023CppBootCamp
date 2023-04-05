#ifndef DYNAMICPTR_H
#define DYNAMICPTR_H

#include <iostream>

template<typename T>
class Dynamicptr
{

public:
    Dynamicptr(T *pointer)
    {
        counter = new int(1);
        parameter= pointer;
    }

    Dynamicptr(const Dynamicptr &cpyPtr)
    {
        this->counter= cpyPtr.counter;

        if (cpyPtr.parameter != nullptr)
        {
            (*counter)++;
        }
    }


    void remove_ptr_cntr()
    {
        if(counter != nullptr)
        {
            (*counter)--;
            if (*counter == 0)
            {
                delete counter;
                delete parameter;
            }
        }
    }

    int getCounter()
    {
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


};

#endif // DYNAMICPTR_H
