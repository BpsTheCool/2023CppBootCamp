#ifndef CDROM_H
#define CDROM_H

#include "storages.h"

class CdRom : public Storages
{
    void setName(){
        storage_name="CdRom"+QString::number(countCdRom);
    }
public:
    CdRom(QObject *parent = nullptr,
          QString storagename="",
          double totalspace=100,
          bool ejectable=true,
          bool IsWritable=true);
    static int countCdRom;
    void eject() override;
    void insert() override;
    void setType();
    void setName(QString name);
};

#endif // CDROM_H
