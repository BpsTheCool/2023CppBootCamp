#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <unordered_map>
#include<memory>
#include<vector>
#include "Iplugable.h"

class Drive;


enum class TypeDevice
{
    null=0,
    Hdd=1,
    Ssd=2,
    Flashmemory=3,
    HardExternal=4,
};


class Device : public Iplugable
{
    std::string m_namedevice;
    const TypeDevice m_typedevice;
    int m_sizedevice;
    std::shared_ptr<Drive> m_defualtDrive;
    std::vector<std::shared_ptr<Drive>> m_drives;
    static inline std::unordered_map<TypeDevice,std::string> m_typenames
    {
        std::make_pair<TypeDevice,std::string>(TypeDevice::Hdd , "Hdd"),
        std::make_pair<TypeDevice,std::string>(TypeDevice::Flashmemory , "Flashmemory"),
        std::make_pair<TypeDevice,std::string>(TypeDevice::Ssd , "Ssd"),
        std::make_pair<TypeDevice,std::string>(TypeDevice::HardExternal , "HardExternal")
    };

public:
    Device()=delete;
    Device(std::string name , int size, const TypeDevice type);
    std::string namedevice() const;
    int sizedevice() const;
    std::vector<std::shared_ptr<Drive>> drives() const;
    TypeDevice typedevice() const;
    static TypeDevice mymap(std::string x);
    std::string mymap() const;

    virtual void insert()=0;
    virtual void eject()=0;


    void setNamedevice(const std::string &newNamedevice);
};

#endif // DEVICE_H
