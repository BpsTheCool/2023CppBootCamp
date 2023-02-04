#include <iostream>
#include "Sharedptr.h"
#include <memory>
#include "Test.h"

using namespace std;

int main()
{

    //Sharedptr::setCount(0);
    int a=7;
    int b=8;
    Sharedptr smartptr(new int(a));
    std::cerr << "a:" ;
    smartptr.printcount();
//    Sharedptr smartptr3(new int(a));
//    std::cerr << "a:" ;
//    smartptr.printcount();
    Sharedptr smartptr2(smartptr);
    std::cerr << "a:" ;
    smartptr.printcount();

    Sharedptr smartptrb(new int(b));
    std::cerr << "b:" ;
    smartptrb.printcount();
    {

        Sharedptr smartptr3(smartptr);
        std::cerr << "a:" ;
        smartptr2.printcount();
    }

    std::cerr << "a:" ;
    smartptr.printcount();



    //-------------------------------------
//    Test a;
//    std::shared_ptr<Test> realptr = std::make_shared<Test> (a);
//        std::cerr<<realptr.use_count();
//    std::shared_ptr<Test> realptr4 = std::make_shared<Test> (a);
//        std::cerr<<realptr.use_count();
//    auto realptr2 = realptr;
//    std::cerr<<realptr.use_count();
//    {
//        auto realptr3 = realptr;
//        std::cerr<<realptr.use_count();
//        std::cerr<<realptr2.use_count();

//    }

//    std::cerr<<realptr.use_count();
    return 0;
}
