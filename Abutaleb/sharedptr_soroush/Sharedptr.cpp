#include "Sharedptr.h"
#include "iostream"


//void Sharedptr::setCount(int newCount)
//{
//    m_count = newCount;
//}

Sharedptr::Sharedptr(int* a)
    :m_a(a)
{
    m_count++;
//    if(count==0){
//        ~Sharedptr();
    //    }
}

Sharedptr::Sharedptr(Sharedptr &a)
{
    //std::cerr << "copy" << std::endl;
    m_a=a.m_a;
    a.m_count++;
    m_count = a.m_count;

}

Sharedptr::~Sharedptr()
{

    std::cerr << "destruct" << std::endl;
    m_count=(this->m_count)-1;


    if(m_count==0){
        delete m_a;
        delete
        std::cerr << "completly delete" <<std::endl;
    }
}

void Sharedptr::printcount()
{
    std::cerr << m_count << std::endl;
}

int Sharedptr::getm_a()
{
    return *m_a;
}




