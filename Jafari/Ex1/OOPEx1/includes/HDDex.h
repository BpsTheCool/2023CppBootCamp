#ifndef HDDEX_H
#define HDDEX_H

#include "InterfaceDevice.h"

class HDDex : public InterfaceDevice
{
    int m_storage;
    bool m_edjectStatus = true;
    bool m_isReadOnly;

public:
    HDDex(int storage, bool isReadOnly);

    int getStorage() override;
    void read() override;
    void write() override;
    void edject(bool status) override;
};

#endif // HDDEX_H
