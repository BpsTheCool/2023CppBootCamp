#ifndef SHARED_PTR_INT_H
#define SHARED_PTR_INT_H


class shared_ptr_int
{

    private:

      int* ptr;
      int* ref_count;

    public:

    shared_ptr_int (int* p = nullptr) ;

    shared_ptr_int (const shared_ptr_int& other) ;

    shared_ptr_int & operator=(const shared_ptr_int& other)  ;

    shared_ptr_int(shared_ptr_int && other)  ;

    shared_ptr_int & operator=(shared_ptr_int && other);

    ~shared_ptr_int() ;

    int& operator*() ;

    void reset(int*) ;

    int use_count() ;
};

int* make_shared_int(int input = 0 ) ;


#endif // SHARED_PTR_INT_H
