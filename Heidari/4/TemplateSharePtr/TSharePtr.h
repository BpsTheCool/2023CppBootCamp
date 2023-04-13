#ifndef TSHAREPTR_H
#define TSHAREPTR_H
#include <iostream>
#include "QDebug"

template<typename T>
class TSharePtr
{
private:

    int *counter;
    T * ptrT = nullptr;
    inline void decreaseCounter()
    {
         (*counter)--;
    }

//*****************************************************************************
    inline void increaseCounter()
    {
         (*counter)++;
    }

//*****************************************************************************
    void clean()
    {
        if(counter != nullptr)
           {
                  (*counter)--;
               if (*counter == 0)
                {
                  if (nullptr != ptrT)
                       delete ptrT;
                    delete counter;
                }
        }

    }

public:
    TSharePtr(T * ptr)
    {
        ptrT = ptr;
        counter = new int(1);
    }

//*****************************************************************************
    TSharePtr(const TSharePtr& refPtr)
    {
        this->ptrT = refPtr.ptrT;
        this->counter= refPtr.counter;

        if (nullptr != refPtr.ptrT)
        {
            increaseCounter();
        }
    }

//*****************************************************************************
    TSharePtr&  operator =(const TSharePtr& refPtr)
    {
        clean();

        this->ptrT = refPtr.ptrT;
        this->counter= refPtr.counter;
        if (nullptr != refPtr.ptrT)
        {
            increaseCounter();
        }
       return *this;
    }

    //*****************************************************************************
      T& operator *() const
        {
            return *ptrT;
        }
//*****************************************************************************

      T* operator ->() const
        {
            return ptrT;
        }
//*****************************************************************************
    TSharePtr(TSharePtr && movedPtr)
    {
        clean();
        this->ptrT = movedPtr.ptrT;
        this->counter= movedPtr.counter;

        movedPtr.ptrT = nullptr;
        movedPtr.counter = nullptr;
    }

//*****************************************************************************
    ~TSharePtr()
    {
       clean();
       qDebug() << "tshare Destruct" ;
    }

//*****************************************************************************
    int getCounter()
    {
        if(counter != nullptr)
        {
         return *counter;
        }
        return 0;
    }

//*****************************************************************************
    T* getAddres()
    {
      return ptrT;
    }

//*****************************************************************************
    T getValue()
    {
      return *ptrT;
    }

//*****************************************************************************
    void reset()
    {
      this->~TSharePtr<T>();
        *counter = 0;
        counter = nullptr;
    }

//*****************************************************************************
    void reset(T *obj)
    {
       this->~TSharePtr<T>();
       new (this) TSharePtr(obj);

    }
};
#endif // TSHAREPTR_H
