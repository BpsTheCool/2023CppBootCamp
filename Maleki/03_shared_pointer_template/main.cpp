#include "smartpointer.h"
#include <iostream>
#include <string>

int main()
{
    shared_pointer a1 = new std::string("Hello!");
    shared_pointer a2 = std::move(a1);
    shared_pointer a3 = a2;
{
    shared_pointer a4 = a3;
}
//    shared_pointer a5 = a4;   error:a4 is destructed

    *a2="Hi!";
    std::cout<<std::endl<< "a2: "<<*a2;
    std::cout<<std::endl<< "a3: "<<*a3;
    std::cout<<std::endl<< "count pointers (a): " <<a3.countPointers();


    shared_pointer<double> b1;
//    b1 = new int(512);
    b1.reset(new double (512.765));
    shared_pointer<double> b2;
    b2=b1;
    shared_pointer<double> b3;
    b3=std::move(b1);
    shared_pointer<double> b4;
    b4=b3;

    std::cout<<std::endl<< "b2: " <<*b2;
    std::cout<<std::endl<< "b3: " <<*b3;
    std::cout<<std::endl<< "b4: " <<*b4;
    std::cout<<std::endl<< "count pointers (b): " <<b2.countPointers();
    std::cout<<std::endl<< "count pointers (a): " <<a3.countPointers();
}
