#ifndef TSAFESHAREPTR_H
#define TSAFESHAREPTR_H
#include <iostream>
#include <mutex>
template<typename T>
class TSafeSharePtr
{
private:

    int *counter;
    T * ptrT = nullptr;
    std::mutex* mMute ;
    inline void decreaseCounter()
    {
         std::lock_guard<std::mutex> lk(*mMute);
         (*counter)--;
    }

//*****************************************************************************
    inline void increaseCounter()
    {
        std::lock_guard<std::mutex> lk(*mMute);
         (*counter)++;
    }

//*****************************************************************************
    void clean()
    {
        std::lock_guard<std::mutex> lk(*mMute);
        if(counter != nullptr)
           {
                  (*counter)--;
               if (*counter == 0)
                {
                  if (nullptr != ptrT)
                       delete ptrT;
                       delete counter;
                       delete mMute;
                }
        }

    }

public:
    TSafeSharePtr(T * ptr)
    {
        ptrT = ptr;
        counter = new int(1);
        mMute = new std::mutex();
    }

//*****************************************************************************
    TSafeSharePtr(const TSafeSharePtr& refPtr)
    {
        this->mMute =refPtr.mMute;
        this->ptrT = refPtr.ptrT;
        this->counter= refPtr.counter;

        if (nullptr != refPtr.ptrT)
        {
            increaseCounter();
        }
    }

//*****************************************************************************
    TSafeSharePtr&  operator =(const TSafeSharePtr& refPtr)
    {
        clean();
        this->mMute =refPtr.mMute;
        std::lock_guard<std::mutex> lk(this->mMute);
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
    TSafeSharePtr(TSafeSharePtr && movedPtr)
    {
                this->mMute =movedPtr.mMute;
        clean();
        this->ptrT = movedPtr.ptrT;
        this->counter= movedPtr.counter;

        movedPtr.ptrT = nullptr;
        movedPtr.counter = nullptr;
    }

//*****************************************************************************
    ~TSafeSharePtr()
    {
       clean();

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
        std::lock_guard<std::mutex> lk(*mMute);
      this->~TSafeSharePtr<T>();
        *counter = 0;
        counter = nullptr;
    }

//*****************************************************************************
    void reset(T *obj)
    {
        std::lock_guard<std::mutex> lk(*mMute);
       this->~TSafeSharePtr<T>();
       new (this) TSafeSharePtr(obj);

    }
};

#endif // TSAFESHAREPTR_H
