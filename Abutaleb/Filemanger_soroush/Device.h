#ifndef DEVICE_H
#define DEVICE_H

#include "Device.h"
#include "Drive.h"
#include"Device.h"
#include "File.h"
#include<iostream>
#include<vector>

using namespace std;

class Plugable
{
public:
    virtual void insert()=0;
    virtual void eject()=0;
};



class Device : public Plugable
{
    string m_name;
    double m_size;
protected:
    bool m_Driveable=true;
public:
    Device(string name , double size);
    string getnamedevice();
    double getsizedevice();
    void   setsizedevice(double newsize);
    bool   Driveable();
    //virtual string getnamedevice()=0;

};

class Hdd : public Device
{
    bool Device::m_Driveable=true;
public:
    Hdd(string name , double size);
    virtual void insert() override;
    virtual void eject() override;
};


class Ssd : public Device
{
    bool Device::m_Driveable=true;
public:
    Ssd(string name , double size);
    virtual void insert() override;
    virtual void eject() override;
};

#endif // DEVICE_H
