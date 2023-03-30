#include "shared_ptr_int.h"


    shared_ptr_int::shared_ptr_int (int* p) : ptr(p)
    {
        if (p)
            ref_count = new int(1) ;
        else
            ref_count = nullptr ;
    }

    // copy semantics
    shared_ptr_int::shared_ptr_int(const shared_ptr_int & other)
        : ptr(other.ptr), ref_count(other.ref_count)
    {
        if (ref_count)
            (*ref_count)++;
    }

    shared_ptr_int& shared_ptr_int:: operator=(const shared_ptr_int& other)
    {
        if (this != &other)
        {
            if (ref_count && --(*ref_count) == 0)
            {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;

            if (ref_count)
                (*ref_count)++;
        }
        return *this;
    }

    // move semantics
    shared_ptr_int::shared_ptr_int(shared_ptr_int && other)
        : ptr(other.ptr), ref_count(other.ref_count)
    {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    shared_ptr_int& shared_ptr_int:: operator=(shared_ptr_int && other)
    {
        if (this != &other)
        {
            if (ref_count && --(*ref_count) == 0)
            {
                delete ptr;
                delete ref_count;
            }

            ptr = other.ptr;
            ref_count = other.ref_count;

            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // destructor
    shared_ptr_int::~shared_ptr_int()
    {
        if (ref_count && --(*ref_count) == 0)
        {
            delete ptr;
            delete ref_count;
        }
    }


    int& shared_ptr_int:: operator*()
    {
       return *ptr;
    }


    void shared_ptr_int:: reset(int* p= nullptr)
    {

        if (ptr != p)
        {
            if (ref_count && --(*ref_count) == 0)
            {
                delete ptr;
                delete ref_count;
            }

            ptr = p;
            if (p)
                ref_count = new int(1);
            else
                ref_count = nullptr;
        }
    }

    int shared_ptr_int::use_count()
    {
        if(!ptr)
            return 0 ;
        return *ref_count ;
    }

    int* make_shared_int (int input)
    {
        return new int(input);
    }
