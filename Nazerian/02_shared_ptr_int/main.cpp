#include <iostream>
#include "shared_ptr_int.h"

int main()
{
    shared_ptr_int p1 , p2 , p3 ;

    p1 = make_shared_int(25) ;

    p2 = p1 ;

    std::cout <<"p1 = "<< *p1 <<" p2 = "<< *p2 << std::endl ;

    p3 = std::move(p2) ;

    std::cout <<"p3 = "<< *p3 <<" p2 = " ;

    if(p2.use_count())
        std::cout << *p2 <<std::endl;
    else
        std::cout << "null " <<std::endl;

    shared_ptr_int p4 = make_shared_int() ;
    std::cout << *p4 ;

    return 0;
}
