#include <iostream>
#include <string>
#include<vector>
#include "Shared_Ptr.h"

using namespace std;


class myclass
{
    public:
    void sorosh(){};
};

int main()
{
    myclass my;
    Sh_Ptr<int> obj(new int(6));
    {
        Sh_Ptr<int>obj2(obj);
        std::cerr <<obj2.counter();
    }
    Sh_Ptr<myclass> mamd;
    mamd->sorosh();
     std::cerr<<obj.counter();
    //std::cerr << b.counter();
     Sh_Ptr<int> obj3 (new int(7));
     std::cerr << *obj3;
//     *obj3=8;
     std::cerr << *obj3;

    return 0;
}
