#include "ExternalHdd.h"

ExternalHdd::ExternalHdd(std::string type)
    :Divice(type)
{

}

ExternalHdd::ExternalHdd(std::string name, int size)
    :File(name,size)
{

}
