#include "shared_ptr.h"
#include <iostream>


int main()
{
    shared_ptr<int> p1 = make_shared<int>(200) , p2 ,p3 , p4 ;
    //shared_ptr<float> f = p1 ;  how to make it happen ?

    p3 = p2 = p1 ;

    //p3 = std::move(p1) ;

    p4 = make_shared<int>(1) ;

//    if(p1.use_count())
//        std::cout <<"p1 = " << *p1 ;
//    std::cout <<" p1.use_count = " << p1.use_count() ;

//    if(p2.use_count())
//        std::cout <<" p2 = " << *p2 ;
//    std::cout <<" p2.use_count = " << p2.use_count() ;

//    if(p3.use_count())
//        std::cout <<" p3 = " << *p3 ;
//    std::cout <<" p3.use_count = " << p3.use_count() ;

//    //p3.reset() ;

//    if(p3.use_count())
//        std::cout <<" p3 = " << *p3 ;
//    std::cout <<" p3.use_count = " << p3.use_count() ;

//    std::cout <<std::endl << (p2.use_count() ? "not rmpty" : "empty" ) ;
//    std::cout<< " p2 = " << *p2<< " p2.use_count = " << p2.use_count() ;

    std::cout << "p3 = "<<*p3 << "p3.use_count = " << p3.use_count() ;
    p3 = p4 ;
    std::cout <<std::endl<< " p2 = " << *p2 << "p2.use_count "<< p2.use_count() ;

    int* p = p1.get() ;

    p1 = p2 = p3 = p4 ;

    std::cout <<std::endl << (p? "not empty" : "empty") ;
    std::cout <<std::endl << *p ;
    return 0;
}
