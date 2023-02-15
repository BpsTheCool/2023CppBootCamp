#ifndef HDD_H
#define HDD_H

#include<string>
#include "Device.h"


class Hdd : public Device
{
public:
    Hdd(std::string name  , int size , const TypeDevice type=TypeDevice::Hdd);
    virtual void insert() override;
    virtual void eject() override;

};

#endif // HDD_H



