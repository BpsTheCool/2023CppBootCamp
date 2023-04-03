#ifndef SHARED_PTR_H
#define SHARED_PTR_H


template<typename T>
class shared_ptr
{
    T* ptr ;
    int* ref_count ;

public:

    shared_ptr(T* p = nullptr) : ptr(p)
    {
        if(p)
            ref_count = new int(1) ;
        else
            ref_count = nullptr ;
    }

//    shared_ptr operator= (T* p )
//    {
//        if(ref_count && --(*ref_count) == 0)
//        {
//            delete ptr ;
//            delete ref_count ;
//        }
//        ptr = p ;
//        if(p)
//            ref_count = new int(1) ;
//        else
//            ref_count = nullptr ;

//        return *this ;
//    }

    //copy semantics
    shared_ptr (const shared_ptr & other ) :ptr(other.ptr) , ref_count(other.ref_count)
    {
        if(ref_count)
            (*ref_count)++ ;
    }

    shared_ptr& operator= ( const shared_ptr& other )
    {
        if(this != &other)
        {
            if(ref_count && --(*ref_count) == 0)
            {
                delete ptr ;
                delete ref_count ;
            }

            ptr = other.ptr ;
            ref_count = other.ref_count ;

            if(ref_count)
                (*ref_count)++ ;
        }

        return *this ;
    }

    //move semantics
    shared_ptr(shared_ptr && other ) :ptr(other.ptr) , ref_count(other.ref_count)
    {
        other.ptr = nullptr ;
        other.ref_count = nullptr ;
    }

    shared_ptr& operator= (shared_ptr&& other)
    {
        if(this != &other )
        {
            if(ref_count && --(*ref_count) == 0 )
            {
                delete ptr ;
                delete ref_count ;
            }

            ptr = other.ptr ;
            ref_count = other.ref_count ;

            other.ptr = nullptr ;
            other.ref_count = nullptr ;
        }

        return *this ;
    }

    ~shared_ptr ()
    {
        if(ref_count && --(*ref_count) == 0 )
        {
            delete ptr ;
            delete ref_count ;
        }
    }

    T& operator* ()
    {
        return *ptr ;
    }

    void reset(T* p = nullptr)
    {
        if(ref_count && --(*ref_count)  == 0 )
        {
            delete ptr ;
            delete ref_count ;
        }

        ptr = p ;
        if(p)
            ref_count = new int (1) ;
        else
            ref_count = nullptr ;

    }

    int use_count()
    {
        if(!ptr)
            return 0 ;
        return *ref_count ;
    }

    int* get()
    {
        return ptr ;
    }

};

template<typename T>
T* make_shared(T input)
{
    return new T (input) ;
}

#endif // SHARED_PTR_H







