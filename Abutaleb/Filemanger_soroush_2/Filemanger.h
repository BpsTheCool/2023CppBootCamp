#ifndef FILEMANGER_H
#define FILEMANGER_H

#include<vector>
#include<memory>

class Device;

class Filemanger
{
    std::vector<std::shared_ptr<Device>> m_device;
public:
    Filemanger(std::vector<std::shared_ptr<Device>>& d);
    void show() const;
    void insertdevice(std::shared_ptr<Device> newone);
    void removedevice(std::string namedevice);
};

#endif // FILEMANGER_H
