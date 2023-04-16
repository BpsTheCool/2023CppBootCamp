#include "Dynamicptr.h"
#include <iostream>
#include <thread>

int main()
{
    //-----------------------------------------------------------//
    std::cerr <<  "//-------------Copy First int parameter------------//" << std::endl;
    //----------------------------------------------------------//
    int * First_param = new int(10);
    Dynamicptr CPY_ptr1(First_param);
    Dynamicptr CPY_ptr3=CPY_ptr1;

    std::cerr << "First_param_copy1" << ": "<<CPY_ptr1.getCounter()<< std::endl;
    {
        Dynamicptr CPY2_ptr1(CPY_ptr1);
        std::cerr << "Inside_area_copying" << ": "<<CPY2_ptr1.getCounter()<< std::endl;
    }
    std::cerr <<  "After_leaving_area" << ": "<<CPY_ptr1.getCounter()<< std::endl;


    // thread handling//
    std::thread a ([&CPY_ptr1]() mutable {

        for (int i=0;i<12000;i++)
        {
            Dynamicptr thread1(CPY_ptr1);
        std::cerr <<  "thread_1 " << ": "<<thread1.getCounter()<< std::endl;
        }
        std::this_thread::sleep_for((std::chrono::seconds(5)));
    });


    std::thread b ([&CPY_ptr1]() mutable {
        for (int i=0;i<12000;i++)
        {
            Dynamicptr thread2(CPY_ptr1);

        std::cerr <<  "thread_1 " << ": "<<thread2.getCounter()<< std::endl;
        }
        std::this_thread::sleep_for((std::chrono::seconds(5)));

    });

    a.join();
    b.join();

    First_param = nullptr;
    delete First_param;

}
