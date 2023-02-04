#ifndef FLASHMEMORY_H
#define FLASHMEMORY_H

#include "storages.h"

class FlashMemory : public Storages
{
    void setName();
public:
    explicit FlashMemory(QObject *parent = nullptr,
                         QString storagename="",
                         double totalspace=100,
                         bool ejectable=true,
                         bool IsWritable=true);
    static int countFlashMemory;
    void eject() override;
    void insert() override;
    void setType();
    void setName(QString name);
};

#endif // FLASHMEMORY_H
