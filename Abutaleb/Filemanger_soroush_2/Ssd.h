#ifndef SSD_H
#define SSD_H

#include<string>
#include "Device.h"

class Ssd : public Device
{
public:
    Ssd(std::string name , int size , const TypeDevice type=TypeDevice::Ssd);
    virtual void insert() override;
    virtual void eject() override;
};

#endif // SSD_H


