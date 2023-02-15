#include<iostream>
#include<iomanip>
#include "Filemanger.h"
#include "Device.h"

Filemanger::Filemanger(std::vector<std::shared_ptr<Device>>& d)
    :m_device(d)
{


}

void Filemanger::show() const
{
    std::cerr << std::endl << "#########################################" << std::endl;
    std::cerr << std::setfill(' ') << std::setw(12) << " " << "Device"<<std::endl;
    std::cerr << "  Name"<< "      " << "size" << "      " << "type";
    std::cerr << std::endl << "----------------------------------------" << std::endl;
    for(auto &item : m_device)
    {
        std::cerr << std::setfill(' ') << std::setw(6) << item->namedevice() << std::setfill(' ') << std::setw(6)<< " " << item->sizedevice() << std::setfill(' ') << std::setw(6)<< " " << item->mymap() << std::endl;

    }
    std::cerr << std::endl << "you have " << m_device.size() << " Devices on your pc" << std::endl;
    std::cerr << std::endl << "----------------------------------------" << std::endl;




    //how can I work with this part ? ;

//    for(auto it=m_device.begin() ; it !=m_device.end() ; it++)
//    {
//        std::cerr << "Device Name : " << it->
//    }

}

std::shared_ptr<Device> Filemanger::insertdevice(std::shared_ptr<Device> newone)
{
    m_device.push_back(newone);
    newone->insert();
}
