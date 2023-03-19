#include <iostream>
#include <string>
#include<vector>
#include "Shared_Ptr.h"

using namespace std;


int main()
{
    Sh_Ptr<int> obj(new int(6));
    {
        Sh_Ptr<int>obj2(obj);
        std::cerr <<obj2.counter();
    }

    std::cerr <<obj.counter();
    //std::cerr << b.counter();
    return 0;
}
