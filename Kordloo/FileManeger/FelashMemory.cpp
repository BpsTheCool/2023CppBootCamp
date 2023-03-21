#include "FelashMemory.h"



FelashMemory::FelashMemory(std::string type)
    :Divice(type)
{

}

FelashMemory::FelashMemory(std::string name, int size)
    :File(name,size)
{

}
