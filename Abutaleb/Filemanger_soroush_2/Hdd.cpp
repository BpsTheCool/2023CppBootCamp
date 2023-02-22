#include "Hdd.h"
#include <iostream>

Hdd::Hdd(std::string name, int size, const TypeDevice type)
    :Device(name,size,type)
{

}

void Hdd::insert()
{
    std::cerr << "Hdd inserted " << std::endl;
}

void Hdd::eject()
{

}
