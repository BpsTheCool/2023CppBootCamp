#include "smartpointer.h"

shared_pointer::shared_pointer():
    m_object(nullptr),
    m_counter(nullptr)
{
}

shared_pointer::shared_pointer(int *new_ptr):
    m_object(new_ptr),
    m_counter(new int(1))
{
}

shared_pointer::shared_pointer(shared_pointer &copy)
    :m_object(copy.getObject())
    ,m_counter(copy.getCounter())
{
    *m_counter+=1;
}

shared_pointer::shared_pointer(shared_pointer &&moved)
    :m_object(moved.getObject())
    ,m_counter(moved.getCounter())
{
    *m_counter+=1;
    moved.setNull();
}

void shared_pointer::operator = (int *new_ptr)
{
    if(m_counter != nullptr){
        if(*m_counter==1){
            delete m_object;
            delete m_counter;
        } else {
            *m_counter-=1;
        }
    }
    m_object = new_ptr;
    m_counter = new int(1);
}

void shared_pointer::operator = (shared_pointer &copy)
{
    if(m_object==copy.getObject()){
        return;
    } else {
        if(m_object != nullptr){
            if(*m_counter==1){
                delete m_object;
                delete m_counter;
            } else {
                *m_counter-=1;
            }
        }
        m_object = copy.getObject();
        m_counter = copy.getCounter();
        *m_counter+=1;
    }
}

void shared_pointer::operator = (shared_pointer &&moved)
{
    if(moved.getObject()==m_object){
        moved.setNull();
    } else {
        if(m_object != nullptr){
            if(*m_counter==1){
                delete m_object;
                delete m_counter;
            } else {
                *m_counter=-1;
            }
        }
        m_object = moved.getObject();
        m_counter=moved.getCounter();
        *m_counter+=1;
        moved.setNull();
    }
}

void shared_pointer::reset(int *new_ptr)
{
    if(m_counter != nullptr){
        if(*m_counter==1){
            delete m_object;
            delete m_counter;
        } else {
            *m_counter-=1;
        }
    }
    m_object = new_ptr;
    m_counter = new int(1);
}

int &shared_pointer::operator *()
{
    return *m_object;
}

int* shared_pointer::getObject()
{
    return m_object;
}

int* shared_pointer::getCounter()
{
    return m_counter;
}

void shared_pointer::setNull()
{
    if(m_object!=nullptr){
        *m_counter-=1;
        if(*m_counter==0){
            delete m_object;
            delete m_counter;
        }
        m_counter=nullptr;
        m_object=nullptr;
    }
}

int shared_pointer::countPointers(){
    return *m_counter;
}

shared_pointer::~shared_pointer(){
    if(m_object!=nullptr){
        *m_counter-=1;
        if(*m_counter==0){
            delete m_object;
            delete m_counter;
        }
    }
}
