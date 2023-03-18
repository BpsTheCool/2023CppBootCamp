
#include <iostream>
#include <string>

template <class T>
class my_shared_ptr
{
private:
    T *m_ptr = nullptr;
    int *ref_count = nullptr;

public:

    my_shared_ptr(T* ptr)
        : m_ptr(ptr)
    {
        ref_count = new int(1);
        std::cout << "constructor called ! " << std::endl;
    }
    ~my_shared_ptr()
    {
        this->decrement_ref_count();
        if(show_Ref_count() == 0)
        {
            delete (ref_count);
            delete (m_ptr);
        }
        std::cout << "destructor called ! \t memory value pointing to:" << *m_ptr << std::endl;
    }



    my_shared_ptr(my_shared_ptr& tocopy)
    {
        tocopy.increment_ref_count();
        ref_count = tocopy.get_ref_count();
        m_ptr = tocopy.ptr();
    }

    my_shared_ptr(my_shared_ptr &&tomove)
    {
        m_ptr = std::move(tomove.ptr());
        ref_count = std::move(tomove.get_ref_count());
        tomove.m_ptr = nullptr;
        tomove.ref_count = nullptr;
    }

    T& operator* ()
    {
        return *m_ptr;
    }

    void operator = (my_shared_ptr& ptr)
    {
        if(this == &ptr)
               return;
        ptr.increment_ref_count();
        ref_count = ptr.get_ref_count();
        this->m_ptr = ptr.ptr();

    }



    T *ptr() const
    {
        return m_ptr;
    }

    int *get_ref_count() const
    {
        return ref_count;
    }

    int show_Ref_count()
    {
        return *ref_count;
    }

    void increment_ref_count()
    {
        (*ref_count)++;
    }

    void decrement_ref_count()
    {
        (*ref_count)--;
    }
    void set_ref_count(int newRef_count)
    {
        (*ref_count) = newRef_count;
    }




};


int main(int argc, char *argv[])
{

//    int *ptr = new int(2);
    my_shared_ptr<int> a_ptr (new int(8));
    std::cerr << "a refcount is: " <<a_ptr.show_Ref_count() << std::endl ;
    my_shared_ptr<int> b_ptr = a_ptr;
    std::cerr << "a refcount is: " <<a_ptr.show_Ref_count() << std::endl ;
    my_shared_ptr<int> c_ptr(new int(111));
    c_ptr = b_ptr;
    std::cerr << "a refcount is: " <<a_ptr.show_Ref_count() << std::endl ;
    my_shared_ptr m_ptr(std::move(a_ptr));
    std::cerr << "a refcount is: " <<m_ptr.show_Ref_count() << std::endl ;
    my_shared_ptr<double> d_ptr(new double (12.987));
    std::cerr << "a is pointing to value: " << *m_ptr << std::endl ;
    std::cerr << "b is pointing to value: " << *b_ptr << std::endl ;
    std::cerr << "c is pointing to value: " << *c_ptr << std::endl ;
    std::cerr << "d is pointing to value: " << *d_ptr << std::endl ;
    std::cerr << "a address is: " << m_ptr.ptr() << std::endl ;
    std::cerr << "b address is: " << b_ptr.ptr() << std::endl ;
    std::cerr << "c address is: " << c_ptr.ptr() << std::endl ;
    std::cerr << "d address is: " << d_ptr.ptr() << std::endl ;
    std::cerr << "a refcount is: " <<m_ptr.show_Ref_count() << std::endl ;
    std::cerr << "b refcount is: "<< b_ptr.show_Ref_count() << std::endl ;
    std::cerr << "c refcount is: "<< c_ptr.show_Ref_count() << std::endl ;
    std::cerr << "d refcount is: "<< d_ptr.show_Ref_count() << std::endl ;

    my_shared_ptr<size_t> e_ptr(new size_t (112312.12312387));
    std::cerr << "e refcount is: "<< e_ptr.show_Ref_count() << std::endl ;
    std::cerr << "e is pointing to value: " << *e_ptr << std::endl ;
    std::cerr << "e address is: " << e_ptr.ptr() << std::endl ;

    my_shared_ptr<char> f_ptr(new char ('f'));
    std::cerr << "f refcount is: "<< f_ptr.show_Ref_count() << std::endl ;
    std::cerr << "f is pointing to value: " << *f_ptr << std::endl ;
    std::cerr << "f address is: " << f_ptr.ptr() << std::endl ;


    my_shared_ptr<std::string> g_ptr(new std::string ("hello world"));
    std::cerr << "g refcount is: "<< g_ptr.show_Ref_count() << std::endl ;
    std::cerr << "g is pointing to value: " << *g_ptr << std::endl ;
    std::cerr << "g address is: " << g_ptr.ptr() << std::endl ;


    return 0;
}
