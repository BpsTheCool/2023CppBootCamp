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
    std::shared_ptr<Device> insertdevice(std::shared_ptr<Device> newone);
};

#endif // FILEMANGER_H
