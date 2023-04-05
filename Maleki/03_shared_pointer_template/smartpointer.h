#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template<typename T>
class shared_pointer
{
    T *m_object;
    int *m_counter;

public:

    shared_pointer():
        m_object(nullptr),
        m_counter(nullptr)
    {
    };

    shared_pointer(T* new_ptr):
        m_object(new_ptr),
        m_counter(new int(1))
    {
    };

    shared_pointer(shared_pointer &copy):
        m_object(copy.m_object)
        ,m_counter(copy.m_counter)
    {
        *m_counter+=1;
    };

    shared_pointer(shared_pointer &&moved):
        m_object(moved.m_object)
        ,m_counter(moved.m_counter)
    {
        *m_counter+=1;
        moved.setNull();
    };

    void operator = (shared_pointer &copy)
    {
        if(m_object==copy.m_object){
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
            m_object = copy.m_object;
            m_counter = copy.m_counter;
            *m_counter+=1;
        }
    };

    void operator = (shared_pointer &&moved)
    {
        if(moved.m_object==m_object){
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
            m_object = moved.m_object;
            m_counter=moved.m_counter;
            *m_counter+=1;
            moved.setNull();
        }
    };

    void reset(T* new_ptr)
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
    };

    T& operator *()
    {
        return *m_object;
    };

    T* getObject()
    {
        return m_object;
    };

    void setNull()
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
    };

    int countPointers()
    {
        return *m_counter;
    };

    ~shared_pointer()
    {
        if(m_object!=nullptr){
            *m_counter-=1;
            if(*m_counter==0){
                delete m_object;
                delete m_counter;
            }
        }
    };
};

#endif // SMARTPOINTER_H
