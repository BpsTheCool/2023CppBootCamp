#include "smartpointer.h"

int &shared_pointer::operator *(){
    return *m_object;
}

std::set<shared_pointer *> *shared_pointer::getSet(){
    return m_set;
}

shared_pointer::shared_pointer():
    m_object(nullptr)
  ,m_set(nullptr)
{

}

shared_pointer::shared_pointer(int *new_ptr)
    :m_object(new_ptr),
      m_set(new std::set<shared_pointer*>)
{
        m_set->insert(this);
}

shared_pointer::shared_pointer(shared_pointer &copy)
    :m_object(copy.getobject())
    ,m_set(copy.getSet())
{
    m_set->insert(this);
}

shared_pointer::shared_pointer(shared_pointer &&moved)
    :m_object(moved.getobject())
    ,m_set(moved.getSet())
{
    m_set->insert(this);
    m_set->erase(&moved);
}

int shared_pointer::countPointers(){
    return m_set->size();
}

shared_pointer::~shared_pointer(){
    if(m_set){
        if(m_set->size()==1){
            delete m_object;
        }
        m_set->erase(this);
    }
}

int *shared_pointer::getobject(){
    return m_object;
}

void shared_pointer::operator =(shared_pointer &&moved)
{
    if(moved.getSet()==getSet()){
        m_set->erase(&moved);
    } else {
        m_object = moved.getobject();
        if(m_set){
            if(m_set->size()==1){
                delete m_object;
            }
            m_set->erase(this);
        }
        m_set=moved.getSet();
        m_set->insert(this);
        m_set->erase(&moved);
    }
}

void shared_pointer::operator =(shared_pointer &copy)
{
    if(copy.getSet()==getSet()){
        return;
    } else {
        if(m_set){
            if(m_set->size()==1){
                delete m_object;
            }
            m_set->erase(this);
        }
        m_object = copy.getobject();
        m_set=copy.getSet();
        m_set->insert(this);
    }

}

void shared_pointer::operator =(int *new_ptr)
{
    if(m_set){
        if(m_set->size()==1){
            delete m_object;
        }
        m_set->erase(this);
    }
    m_object = new_ptr;
    m_set=new std::set<shared_pointer*>;
    m_set->insert(this);
}
