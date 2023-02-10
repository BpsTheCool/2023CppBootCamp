#include "Filemanger.h"
#include "Device.h"
#include "Drive.h"
#include "File.h"
#include<vector>

using namespace std;

Filemanger::Filemanger(vector<Device *> &device , vector<Drive *> &derive )
                    : m_device(device) ,
                      m_drive(derive)
{

}

void Filemanger::print()
{
    cout << "Devices: ";
    for(auto it= m_device.begin() ; it != m_device.end() ; ++it){
        cout << (*it)->getnamedevice()<< "  " << (*it)->getsizedevice() << endl;
    }
    cout << "Drives: ";
    for(auto it= m_drive.begin() ; it != m_drive.end() ; ++it){
        cout << (*it)->namedrive() << "  "<< (*it)->sizedrive() << endl;
    }
}

Drive* Filemanger::adddrive(Drive* dr , Device* d)
{
   m_drive.push_back(dr);
   return dr;
}

void Filemanger::insertdevice(Plugable* p)
{

}
