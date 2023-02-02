#include <iostream>
#include "Sharedptr.h"
#include <memory>
#include "Test.h"

using namespace std;

int main()
{
    //Sharedptr::setCount(0);
    int a=7;
    Sharedptr smartptr(new int(a));
    smartptr.printcount();
    Sharedptr smartptr2(smartptr);
    smartptr.printcount();
    {

        Sharedptr smartptr2(smartptr);
        smartptr2.printcount();
    }

    smartptr.printcount();



    //-------------------------------------
//    int a=8;
//    std::shared_ptr<Test> realptr = std::make_shared<Test> ();
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
