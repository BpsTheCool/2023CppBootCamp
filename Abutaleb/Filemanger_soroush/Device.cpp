
#include "Drive.h"
#include "Device.h"
#include "File.h"
#include<iostream>
#include<vector>
#include<string>




Device::Device(string name, double size)
            :m_name(name) , m_size(size)
{

}

string Device::getnamedevice()
{
    return m_name;
}

double Device::getsizedevice()
{
    return m_size;
}

void Device::setsizedevice(double newsize)
{
    m_size=newsize;
}

bool Device::Driveable()
{
 return m_Driveable;
}

Hdd::Hdd(string name , double size )
        :Device(name , size)
{

}

void Hdd::insert()
{
    cout<<"Hdd have just inserted"<<endl;
}

void Hdd::eject()
{
    cout<<"Hdd have just ejected"<<endl;
}

Ssd::Ssd(string name , double size)
        :Device(name , size)
{

}

void Ssd::insert()
{
    cout<<"Ssd have just inserted"<<endl;
}

void Ssd::eject()
{
    cout<<"Ssd have just ejected"<<endl;
}


