#include "Device.h"
#include <iostream>
#include"Drive.h"

//Device::Device()
//{

//}

TypeDevice Device::typedevice() const
{
    return m_typedevice;
}

TypeDevice Device::mymap(std::string x)
{
    for( auto &item : m_typenames)
    {
        if(item.second==x)
        {
            return item.first;
        }
    }
    std::cerr << "I don't know the type of this Device , please insert valid devic"<<std::endl;
    std::cerr << "valid Device:'Hdd','Ssd','Flashmemory','HardExternal'"<<std::endl;
    return TypeDevice::null;
}

std::string Device::mymap() const
{
        auto it = m_typenames.find(m_typedevice);
        if(it !=m_typenames.end())
        {
            return it->second;
        }
        else
        {
            std::string temp = "Unknown type";
            return temp;
        }
}

std::vector<std::shared_ptr<Drive> > Device::drives() const
{
    return m_drives;
}

void Device::setNamedevice(const std::string &newNamedevice)
{
    m_namedevice = newNamedevice;
}

Device::Device(std::string name,  int size, const TypeDevice type )
    :m_namedevice(name)  ,  m_sizedevice(size),  m_typedevice(type)
{
    m_defualtDrive = std::make_shared<Drive>("Main Drive" , size);
    m_drives.push_back(m_defualtDrive);
}


std::string Device::namedevice() const
{
    return m_namedevice;
}

int Device::sizedevice() const
{
    return m_sizedevice;
}

