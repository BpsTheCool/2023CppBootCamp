#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <mutex>

template<typename T>
class shared_pointer
{
    T *m_object;
    int *m_counter;
    std::mutex *m_mutex;

public:

    shared_pointer():
        m_object(nullptr),
        m_counter(nullptr),
        m_mutex(nullptr)
    {
    };

    shared_pointer(T* new_ptr):
        m_object(new_ptr),
        m_counter(new int(1)),
        m_mutex(new std::mutex)
    {
    };

    shared_pointer(shared_pointer &copy)
    {
        m_mutex=copy.m_mutex;
        if(copy.m_object!=nullptr){
            m_object=copy.m_object;
            m_counter=copy.m_counter;
            std::lock_guard<std::mutex> lock(*m_mutex);
            *m_counter+=1;
        }
    };

    shared_pointer(shared_pointer &&moved)
    {
        m_mutex=moved.m_mutex;
        m_object=moved.m_object;
        m_counter=moved.m_counter;
        {
            std::lock_guard<std::mutex> lock(*m_mutex);
            *m_counter+=1;
        }
        moved.setNull();
    };

    void operator = (shared_pointer &copy)
    {
        if(m_object==copy.m_object){
            return;
        } else {
            m_mutex = copy.m_mutex;
            if(m_object != nullptr){
                std::lock_guard<std::mutex> lock(*m_mutex);
                if(*m_counter==1){
                    delete m_object;
                    delete m_counter;
                    delete m_mutex;
                } else {
                    *m_counter-=1;
                }
            }
            m_object = copy.m_object;
            m_counter = copy.m_counter;
            std::lock_guard<std::mutex> lock(*m_mutex);
            *m_counter+=1;
        }
    };

    void operator = (shared_pointer &&moved)
    {
        if(moved.m_object==m_object){
            moved.setNull();
        } else {
            m_mutex = moved.m_mutex;
            {
                std::lock_guard<std::mutex> lock(*m_mutex);
                if(m_object != nullptr){
                    if(*m_counter==1){
                        delete m_object;
                        delete m_counter;
                        delete m_mutex;
                    } else {
                        *m_counter=-1;
                    }
                }
                m_object = moved.m_object;
                m_counter= moved.m_counter;
                *m_counter+=1;
            }
            moved.setNull();
        }
    };

    void reset(T* new_ptr)
    {
        if(m_counter != nullptr){
            std::lock_guard<std::mutex> lock(*m_mutex);
            if(*m_counter==1){
                delete m_object;
                delete m_counter;
                delete m_mutex;
            } else {
                *m_counter-=1;
            }
        }
        m_object = new_ptr;
        m_counter = new int(1);
        m_mutex = new std::mutex;
    };

    T& operator *()
    {
        std::lock_guard<std::mutex> lock(*m_mutex);
        return *m_object;
    };

    T* getObject()
    {
        std::lock_guard<std::mutex> lock(*m_mutex);
        return m_object;
    };

    void setNull()
    {
        if(m_object!=nullptr){
            std::lock_guard<std::mutex> lock(*m_mutex);
            *m_counter-=1;
            if(*m_counter==0){
                delete m_object;
                delete m_counter;
                delete m_mutex;
            }
            m_counter=nullptr;
            m_object=nullptr;
            m_mutex=nullptr;
        }
    };

    int countPointers()
    {
        std::lock_guard<std::mutex> lock(*m_mutex);
        return *m_counter;
    };

    ~shared_pointer()
    {
        if(m_object!=nullptr){
            std::lock_guard<std::mutex> lock(*m_mutex);
            *m_counter-=1;
            if(*m_counter==0){
                delete m_object;
                delete m_counter;
                delete m_mutex;
            }
        }
    };
};

#endif // SMARTPOINTER_H
