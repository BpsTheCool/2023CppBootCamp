#include "smartpointer.h"
#include <iostream>
#include <string>
#include <thread>
#include <vector>

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



    //for testing thread
    std::thread t1([&bx=b3]() mutable {
        std::vector<shared_pointer<double>> sp(10000);
        for (auto &item:sp) {
            item=bx;
            std::cout<<std::endl <<bx.countPointers();
        }
        std::this_thread::sleep_for((std::chrono::seconds(6)));
    });

    std::thread t2([&bx=b3]() mutable {
        std::vector<shared_pointer<double>> sp(10000);
        for (auto &item:sp) {
            item=bx;
            std::cout<<std::endl <<bx.countPointers();
        }
        std::this_thread::sleep_for((std::chrono::seconds(6)));
    });

    std::this_thread::sleep_for((std::chrono::seconds(6)));
    t1.join();
    t2.join();
}
