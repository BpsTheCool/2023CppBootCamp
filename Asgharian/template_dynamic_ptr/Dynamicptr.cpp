# include  "Dynamicptr.h"

/*
template<typename T>
Dynamicptr<T>::Dynamicptr (T *pointer)
{
    counter = new int(1);
    parameter= pointer;
}

template<typename T>
Dynamicptr<T>::Dynamicptr (const Dynamicptr &cpyPtr)
{
    this->counter= cpyPtr.counter;

    if (cpyPtr.parameter != nullptr)
    {
        (*counter)++;
    }
}

template<typename T>
int Dynamicptr<T>::getCounter()
{
    if(counter != nullptr)
    {
        return *counter;
    }
    return 0;
}
template<typename T>
void Dynamicptr<T>::remove_ptr_cntr()
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
template<typename T>
Dynamicptr<T>::~Dynamicptr()
{
    remove_ptr_cntr();
}

template Dynamicptr<int>;
template Dynamicptr<double>;
*/



