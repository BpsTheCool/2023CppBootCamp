#include "Hdd.h"
#include <iostream>

Hdd::Hdd(std::string type)
    :Divice(type)
{

}

Hdd::Hdd(std::string name, int size)
    :File(name,size)
{

}




