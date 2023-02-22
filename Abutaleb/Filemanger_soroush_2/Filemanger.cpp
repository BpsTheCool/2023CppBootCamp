#include<iostream>
#include<iomanip>
#include "Filemanger.h"
#include "Device.h"
#include "Drive.h"

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
        std::cerr << std::setfill(' ') << std::setw(6) << item->namedevice();
        std::cerr << std::setfill(' ') << std::setw(6)<< " " << item->sizedevice();
        std::cerr << std::setfill(' ') << std::setw(6)<< " " << item->mymap() << std::endl;//type of Device
    }
    std::cerr << std::endl << "you have " << m_device.size() << " Derives on your pc" << std::endl;
    std::cerr << std::endl << "----------------------------------------" << std::endl;




    //how can I work with this part ? ;

//    for(auto it=m_device.begin() ; it !=m_device.end() ; it++)
//    {
//        std::cerr << "Device Name : " << it->
//    }

}

void Filemanger::showdrives(std::shared_ptr<Device> selectedDevice) const
{
    auto vectordrives = selectedDevice -> drives();
    std::cerr << std::endl << "#########################################" << std::endl;
    std::cerr << std::setfill(' ') << std::setw(12) << " " << "Derives"<<std::endl;
    std::cerr << "  Name"<< "      " << "size" << "      " << "type";
    std::cerr << std::endl << "----------------------------------------" << std::endl;
    for(auto &item : vectordrives)
    {
        std::cerr << std::setfill(' ') << std::setw(6) << item->namedrive();
        std::cerr << std::setfill(' ') << std::setw(6)<< " " << item->sizedrive() << std::endl;
    }
    std::cerr << std::endl << "you have " << vectordrives.size() << " Devices on your pc" << std::endl;
    std::cerr << std::endl << "----------------------------------------" << std::endl;
}

void Filemanger::insertdevice(std::shared_ptr<Device> newone)
{
    m_device.push_back(newone);
    newone->insert();
}

void Filemanger::removedevice(std::string namedevice)
{
    bool flag=false;
    for (auto it=m_device.begin() ; it !=m_device.end() ; )
    {
        if(namedevice == (*it)->namedevice())
        {
            std::cerr << "it works" << std::endl;
            m_device.erase(it);
            flag=true;
            break; // how this part works?
        }
        else
        {
            ++it;
        }
    }
    if(flag==false)
    {
    std::cerr << "we could't find Device with this name";
    }
}

void Filemanger::renamedevice(std::string namedevice)
{
    for(auto &item : m_device)
    {
       if(item->namedevice()==namedevice)
       {
           std::cerr << "Device exist, please type new name: ";
           std::string newname;
           std:: cin >> newname;
           item->setNamedevice(newname);
       }
    }

    std::cerr << "there is NO Device with this name";
}

std::shared_ptr<Device> Filemanger::selectDevice(std::string nameforselecting)// how can i return this with &  and  nullptr
{
    for(auto &item : m_device)
    {
       if(item->namedevice()==nameforselecting)
       {
           return item;
       }
    }
    std::cerr << "There is no Device with this name";
    return nullptr;

}
