
#include <iostream>

class shared_ptr
{
private:
    int *m_ptr = nullptr;
    shared_ptr *parent_ptr = nullptr;
    int ref_count = 1;

public:

    ~shared_ptr()
    {
        ref_count--;
        equlize_ref_counts(ref_count);
        if(ref_count == 0)
            delete (m_ptr);
        std::cout << "destructor called ! \t memory location pointing to:" << *m_ptr << std::endl;
    }

    shared_ptr(int* ptr)
        : m_ptr(ptr)
    {

    }

    shared_ptr(shared_ptr& ptr)
    {
        parent_ptr = &ptr;
        ref_count = ptr.getRef_count() + 1;
        m_ptr = ptr.ptr();
        equlize_ref_counts(ref_count);
    }

    int& operator* ()
    {
        return *m_ptr;
    }

    void operator = (shared_ptr& ptr)
    {
        parent_ptr = &ptr;
        ref_count = ptr.getRef_count() + 1;
        m_ptr = ptr.ptr();
        equlize_ref_counts(ref_count);
    }

    void setPtr(int *newPtr)
    {
        m_ptr = newPtr;
    }

    int *ptr() const
    {
        return m_ptr;
    }

    int getRef_count() const
    {
        return ref_count;
    }

    void setRef_count(int newRef_count)
    {
        ref_count = newRef_count;
    }

    void equlize_ref_counts(int count)
    {
        ref_count = count;
        if(!parent_ptr)
            return;
        parent_ptr->equlize_ref_counts(count);
    }

};


int main(int argc, char *argv[])
{

//    int *ptr = new int(2);
    shared_ptr a_ptr (new int(8));
    std::cerr << "a refcount is: " <<a_ptr.getRef_count() << std::endl ;
    shared_ptr b_ptr = a_ptr;
    std::cerr << "a refcount is: " <<a_ptr.getRef_count() << std::endl ;
    shared_ptr c_ptr(new int());
    c_ptr = b_ptr;
    std::cerr << "a refcount is: " <<a_ptr.getRef_count() << std::endl ;
    shared_ptr d_ptr(new int (12));
    std::cerr << "a is pointing to value: " << *a_ptr << std::endl ;
    std::cerr << "b is pointing to value: " << *b_ptr << std::endl ;
    std::cerr << "c is pointing to value: " << *c_ptr << std::endl ;
    std::cerr << "d is pointing to value: " << *d_ptr << std::endl ;
    std::cerr << "a address is: " << a_ptr.ptr() << std::endl ;
    std::cerr << "b address is: " << b_ptr.ptr() << std::endl ;
    std::cerr << "c address is: " << c_ptr.ptr() << std::endl ;
    std::cerr << "d address is: " << d_ptr.ptr() << std::endl ;
    std::cerr << "a refcount is: " <<a_ptr.getRef_count() << std::endl ;
    std::cerr << "b refcount is: "<< b_ptr.getRef_count() << std::endl ;
    std::cerr << "c refcount is: "<< c_ptr.getRef_count() << std::endl ;
    std::cerr << "d refcount is: "<< d_ptr.getRef_count() << std::endl ;




    return 0;
}
