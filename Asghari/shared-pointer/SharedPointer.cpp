#include "SharedPointer.h"
#include <iostream>

MySharedPtr::MySharedPtr(int* ptr)
    :m_ptr(ptr),
     m_ref_count(new int(0))
{

}

MySharedPtr::MySharedPtr(const MySharedPtr &copy)
    :m_ptr(copy.m_ptr),
     m_ref_count(copy.m_ref_count)
{

}

int &MySharedPtr::operator*() const
{
    return *m_ptr;
}

int *MySharedPtr::operator->() const
{
    return m_ptr;
}

MySharedPtr &MySharedPtr::operator=(const MySharedPtr &copy)
{

    if (this != &copy) {
        if (--(*m_ref_count) == 0) {
            delete m_ptr;
            delete m_ref_count;
        }
        m_ptr = copy.m_ptr;
        m_ref_count = copy.m_ref_count;
        ++(*m_ref_count);
        }
    return *this;
}

void MySharedPtr::getRefCountr()
{
    std::cout<< *m_ref_count << std::endl;
}

MySharedPtr::~MySharedPtr()
{
    if (--(*m_ref_count) == 0) {
                delete m_ptr;
                delete m_ref_count;
    }
}

