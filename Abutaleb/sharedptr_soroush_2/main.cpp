#include <iostream>
#include"shared_ptr.h"
#include<memory>

class A
{
public:
    A(){};
    void test()
    {

    }
};

int main()
{
    std::shared_ptr<A> test;
    test->test();
    int* g=new int (8);
    Shared_ptr<int> a(g);
    auto b =a;
    std::cerr << b.use_count();
    std::cerr << a.use_count();
    std::cerr << *b;

//    A l;
    Shared_ptr<A> soroush(new A());
    soroush->test();
    std::cerr << soroush.use_count();

    soroush.reset();
    int* sg;
    if(soroush==sg)
    {
        std::cerr << "it works" << std::endl;
    }
    else
    {
        std::cerr << "it dosen't work" << std::endl;
    }

    return 0;
}
