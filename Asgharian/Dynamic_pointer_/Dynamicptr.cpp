# include  "Dynamicptr.h"



Dynamicptr::Dynamicptr (int *pointer)
{
    counter = new int(1);
    parameter= pointer;
}


Dynamicptr::Dynamicptr (const  Dynamicptr &cpyPtr)
{
    this->counter= cpyPtr.counter;

    if (cpyPtr.parameter != nullptr)
    {
        (*counter)++;
    }
}


int Dynamicptr::getCounter()
{
    if(counter != nullptr)
    {
        return *counter;
    }
    return 0;
}
void Dynamicptr::remove_ptr_cntr()
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

Dynamicptr::~Dynamicptr()
{
    remove_ptr_cntr();
}



