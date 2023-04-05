#ifndef FLASH_H
#define FLASH_H

#include "InterfaceDevice.h"

class Flash : public InterfaceDevice
{
    int m_storage;
    bool m_edjectStatus = true;
    bool m_isReadOnly;

public:
    Flash(int storage, bool isReadOnly);

    int getStorage() override;
    void read() override;
    void write() override;
    void edject(bool status) override;
};

#endif // FLASH_H
