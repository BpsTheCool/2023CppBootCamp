#ifndef HDDINTERNAL_H
#define HDDINTERNAL_H
#include "IDrive.h"

class HddInternal : public IDrive
{

public:
    HddInternal();
    bool isEnoughSpace(float size)  override;
    std::list<FileClass> showFileList() override;
     void addFile(FileClass file) override;;
     void deleteFile(FileClass file) override;;

     void setCapacity(float val);
     float getCapacity();

};

#endif // HDDINTERNAL_H
