#ifndef INTERFACEDEVICE_H
#define INTERFACEDEVICE_H

#include <QDebug>

class InterfaceDevice
{
public:
    InterfaceDevice();

    virtual int getStorage() = 0;
    virtual void read() = 0;
    virtual void write() = 0;
    virtual void edject(bool status) = 0;
};

#endif // INTERFACEDEVICE_H
