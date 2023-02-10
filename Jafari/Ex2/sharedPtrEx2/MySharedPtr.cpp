#include "MySharedPtr.h"
#include <QDebug>

MySharedPtr::MySharedPtr()
{
    qDebug()<< "please give an integer as MySharedPtr input!";
}

MySharedPtr::MySharedPtr(int shP)
//    : m_SharedPtr(shP)
{
    m_SharedPtr = new int(shP);
    m_SharedCounter = new int(0);
    qDebug()<< "new shared pointer added:"<< *m_SharedPtr;
    plusSharedCounter();
}

MySharedPtr::~MySharedPtr()
{
    qDebug()<< "destructor shared pointer:"<< *m_SharedPtr;
    (*m_SharedCounter)--;
    if ((*m_SharedCounter) == 0) {
        qDebug()<< "deleted shared pointer:"<< *m_SharedPtr;
        delete this->m_SharedPtr;
        delete this->m_SharedCounter;
    }
}

MySharedPtr::MySharedPtr(MySharedPtr &copy)
{
    this->m_SharedPtr = copy.m_SharedPtr;
    this->m_SharedCounter = copy.m_SharedCounter;
    qDebug()<< "copied shared pointer:"<< *m_SharedPtr;
    plusSharedCounter();
}

void MySharedPtr::getSharedCounter() const
{
    qDebug()<< "SharedPtr Counter:"<< *m_SharedCounter;
}

void MySharedPtr::plusSharedCounter()
{
    (*m_SharedCounter)++;
    qDebug()<< "counter increase for shared pointer:"<< *m_SharedPtr;
}
