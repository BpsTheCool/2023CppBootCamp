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
    void showdrives(std::shared_ptr<Device> selectedDevice) const;
    void insertdevice(std::shared_ptr<Device> newone);
    void removedevice(std::string namedevice);
    void renamedevice(std::string namedevice);
    std::shared_ptr<Device> selectDevice(std::string nameforselecting);
};

#endif // FILEMANGER_H
