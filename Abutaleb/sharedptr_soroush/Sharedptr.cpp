#include "Sharedptr.h"
#include "iostream"


//void Sharedptr::setCount(int newCount)
//{
//    m_count = newCount;
//}

Sharedptr::Sharedptr(int* a)
    :m_a(a)
{
    //m_ptr=*this;
    m_count=new int(0);
    (*m_count)++;

}

Sharedptr::Sharedptr(Sharedptr &a)
{
    //std::cerr << "copy" << std::endl;
    m_a=a.m_a;
    (*a.m_count)++;
    //std::cerr << *a.m_count++ ;
    m_count=a.m_count;
}

Sharedptr::~Sharedptr()
{

    std::cerr << "destruct" << std::endl;
    (*m_count)--;

    if((*m_count)==0){
        delete m_a;
        std::cerr << "completly delete" <<std::endl;
    }
}

void Sharedptr::printcount()
{
    std::cerr << *m_count << std::endl;
}

int Sharedptr::getm_a()
{
    return *m_a;
}




