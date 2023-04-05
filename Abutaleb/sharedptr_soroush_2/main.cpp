#include <iostream>
#include"shared_ptr.h"
#include<memory>
#include<thread>

extern int test;

//class A
//{
//public:
//    A(){};
//    void test()
//    {

//    }
//};


void makeSmartPointer(Shared_ptr<int> &a)
{
    for (int var = 0; var < 100000; ++var)
    {
        new Shared_ptr<int>(a);
    }

}

int main()
{
//    std::shared_ptr<A> test;
//    test->test();
//    int* g=new int (8);
//    Shared_ptr<int> a(g);
//    auto b =a;
//    std::cerr << b.use_count();
//    std::cerr << a.use_count();
//    std::cerr << *b;

////    A l;
//    Shared_ptr<A> soroush(new A());
//    soroush->test();
//    std::cerr << soroush.use_count();

//    soroush.reset();
//    int* sg;
//    if(soroush==sg)
//    {
//        std::cerr << "it works" << std::endl;
//    }
//    else
//    {
//        std::cerr << "it dosen't work" << std::endl;
//    }

    Shared_ptr<int> aa;
    std::thread a(makeSmartPointer,std::ref(aa));
    std::thread b(makeSmartPointer,std::ref(aa));
    a.join();
    b.join();

    std::cerr<< std::this_thread::get_id() << "   " << aa.use_count()<<std::endl;;



    return 0;
}
