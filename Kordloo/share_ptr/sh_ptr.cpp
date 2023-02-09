#include"sh_ptr.h"
#include<iostream>

sh_ptr::sh_ptr(int* nom)
    :nomber(nom)
 {
    m_counter=new int(0);
    (*m_counter)++;

}

sh_ptr::sh_ptr(sh_ptr &conter)
{ 

    m_counter=conter.m_counter;
    (*m_counter)++;
    conter.m_counter=m_counter;
}

sh_ptr::~sh_ptr()
{
    (*m_counter)--;
    if((*m_counter)==0)
        delete[]m_counter;

}

int sh_ptr::getShareptr()
{
    return *m_counter;
}
