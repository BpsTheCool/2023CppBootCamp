#include "Dynamicptr.h"
#include <iostream>

int main()
{
    //-----------------------------------------------------------//
        std::cerr <<  "//-------------Copy First parameter------------//" << std::endl;
    //----------------------------------------------------------//
    int * First_param = new int(10);
    Dynamicptr CPY_ptr1(First_param);
    std::cerr << "First_param_copy1" << ": "<<CPY_ptr1.getCounter()<< std::endl;
    {
        Dynamicptr CPY2_ptr1(CPY_ptr1);
        std::cerr << "Inside_area_copying" << ": "<<CPY2_ptr1.getCounter()<< std::endl;
    }
    std::cerr <<  "After_leaving_area" << ": "<<CPY_ptr1.getCounter()<< std::endl;

    First_param = nullptr;
    delete First_param;
//-----------------------------------------------------------//
    std::cerr <<  "//-------------Copy Second parameter------------//" << std::endl;
//----------------------------------------------------------//
    int * second_Param = new int(5);
    Dynamicptr CPY_ptr2(second_Param);
    std::cerr <<  "second_Param_copy1" << ": "<<CPY_ptr2.getCounter()<< std::endl;

    {
        Dynamicptr CPY2_ptr2(CPY_ptr2);
        std::cerr <<  "Inside_area_copying" << ": "<<CPY2_ptr2.getCounter()<< std::endl;
    }
    std::cerr <<  "After_leaving_area" << ": "<<CPY_ptr2.getCounter()<< std::endl;

    second_Param = nullptr;
    delete second_Param;


}
