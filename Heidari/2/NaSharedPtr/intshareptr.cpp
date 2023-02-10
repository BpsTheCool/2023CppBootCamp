#include "intshareptr.h"

int IntSharePtr::getValueOfInt()
{
    return *ptrInt;
}

/**********************************************************************************/
void IntSharePtr::decreaseCounter()
{
   (*counter)--;
}

/**********************************************************************************/
void IntSharePtr::increaseCounter()
{
    (*counter)++;
}

/**********************************************************************************/
void IntSharePtr::clean()
{
    if(counter != nullptr)
    {
           (*counter)--;
        if (*counter == 0)
         {
           if (nullptr != ptrInt)
                delete ptrInt;
             delete counter;
         }    }


}

/**********************************************************************************/
IntSharePtr::IntSharePtr(int * ptr)
{
    ptrInt = ptr;
    counter = new int(1);

}

/**********************************************************************************/
IntSharePtr::IntSharePtr(const  IntSharePtr& refPtr)
{
    this->ptrInt = refPtr.ptrInt;
    this->counter= refPtr.counter;

    if (nullptr != refPtr.ptrInt)
    {
        increaseCounter();
    }
}

/**********************************************************************************/
IntSharePtr &IntSharePtr::operator =(const IntSharePtr &refPtr)
{
    clean();

    this->ptrInt = refPtr.ptrInt;
    this->counter= refPtr.counter;
    if (nullptr != refPtr.ptrInt)
    {
        increaseCounter();
    }
   return *this;
}

/**********************************************************************************/
IntSharePtr::IntSharePtr(IntSharePtr &&movedPtr)
{
      clean();
      this->ptrInt = movedPtr.ptrInt;
      this->counter= movedPtr.counter;

      movedPtr.ptrInt = movedPtr.counter = nullptr;
}

IntSharePtr::~IntSharePtr()
{
   clean();
}

/**********************************************************************************/
int IntSharePtr::getCounter()
{
    if(counter != nullptr)
    {
     return *counter;
    }
    return 0;
   // return this->counter ;
}

/**********************************************************************************/
int* IntSharePtr::getAddres()
{
    return ptrInt;
}

