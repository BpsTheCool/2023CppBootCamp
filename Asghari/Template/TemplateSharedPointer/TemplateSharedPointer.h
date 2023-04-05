#ifndef TEMPLATESHAREDPOINTER_H
#define TEMPLATESHAREDPOINTER_H

template <typename T>
class MySharedPtr
{

private:
    T* m_ptr;
    int* m_counter;

public:

    MySharedPtr(T* ptr)
        :m_ptr(ptr),
         m_counter(new int(0))
    {

    }

    MySharedPtr(const MySharedPtr &copy)
        :m_ptr(copy.m_ptr),
          m_counter(copy.m_counter)
    {

    }

    T& operator*() const
    {
        return *m_ptr;
    }

    T* operator->() const
    {
        return m_ptr;
    }

    MySharedPtr& operator=(const MySharedPtr &copy)
    {

        if (this != &copy) {
            if (--(*m_counter) == 0) {
                delete m_ptr;
                delete m_counter;
            }
            m_ptr = copy.m_ptr;
            m_counter = copy.m_counter;
            ++(*m_counter);
        }
        return *this;
    }

    void getCounter()
    {
        std::cout<< *m_counter << std::endl;
    }

    ~MySharedPtr()
    {
        if (--(*m_counter) == 0) {
            delete m_ptr;
            delete m_counter;
        }
    }




};




#endif // TEMPLATESHAREDPOINTER_H
