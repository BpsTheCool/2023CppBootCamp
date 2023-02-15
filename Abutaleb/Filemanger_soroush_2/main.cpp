#include<iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include<functional>
#include "Filemanger.h"
#include "Iplugable.h"
#include "Device.h"
#include "Hdd.h"
#include "Ssd.h"

enum class filecommand
{
    adddevice,
    removedevice,
};

std::string user()
{
    std::cerr << std::endl << "************************************************"<<std::endl;
    std::cerr << "command: ";
    std::cerr << "adddevice/insertdevice";
    std::string s;
    std::cerr << std::endl;
    std::cin >> s;
    return s;
}

void switchonTypeDevice(Filemanger &f)
{
    std::cerr << "please write the type of your Device" << std::endl;
    std::string st;
    std::cin>>st;
    TypeDevice sw = Device::mymap(st);
    std::cerr << "please write the name and size of your Device" << std::endl;
    std::string name;
    int size;
    std::cin >> name >>size ;

    switch (sw)
    {
        case TypeDevice::Hdd :
        {
            f.insertdevice(std::make_shared<Hdd>(name,size,sw));
            break;
        }
        case TypeDevice::Ssd :
        {
            f.insertdevice(std::make_shared<Ssd>(name,size,sw));
            break;
        }
    }
}


//using p=std::make_pair<std::string , filecommand>;


int main()
{
    //--------------------------------------
    // you can add new comment in this part;
    //--------------------------------------

    std::unordered_map<std::string , filecommand> o_map
    {
    std::make_pair<std::string , filecommand>("adddevice" ,filecommand::adddevice),
    std::make_pair<std::string , filecommand>("insertdevice" ,filecommand::adddevice),
    std::make_pair<std::string , filecommand>("test" ,filecommand::adddevice),
    std::make_pair<std::string , filecommand>("test" ,filecommand::adddevice),
    std::make_pair<std::string , filecommand>("test" ,filecommand::adddevice),
    std::make_pair<std::string , filecommand>("test" ,filecommand::adddevice),
    std::make_pair<std::string , filecommand>("test" ,filecommand::adddevice)
    };

    std::vector<std::shared_ptr<Device>> devices;

    //program starter.....

    loopstarter:

        std::cerr << "your don't have any device pleases insert one(Hdd/Ssd)" << std::endl;
        std::string firstdevice;
        std::cin >> firstdevice;

        if(firstdevice=="Hdd")
        {
            std::cerr << "please type name & size of Hdd device"<<std::endl;
            std::string Hddname;
            int Hddsize;
            std::cin >> Hddname >>Hddsize;
            devices.push_back(std::make_shared<Hdd>(Hddname,Hddsize));
        }
        else if(firstdevice=="Ssd")
        {
            std::cerr << "please type name & size of Hdd device"<<std::endl;
            std::string Ssdname;
            int Ssdsize;
            std::cin >> Ssdname >> Ssdsize;
            devices.push_back(std::make_shared<Ssd>(Ssdname,Ssdsize));
        }
        else
        {
            std::cerr << "you did't put any device , please try again....." << std::endl;
            goto loopstarter;
        }
        Filemanger manger(devices);

    loop:
        manger.show();
        std::string yourcomment= user();
        auto found=o_map.find(yourcomment);

        if(found !=o_map.end())
        {

            //this is the heart of project
            switch (found->second)
            {
            case filecommand::adddevice:
                switchonTypeDevice(manger);
                goto loop;
            default:
                break;
            }

        }

        else
        {
            std::cerr << "your comment is not found , please correct your comment" <<std::endl;
            goto loop;
        }


    //filecommand x;





}
