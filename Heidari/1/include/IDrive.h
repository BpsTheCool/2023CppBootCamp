#ifndef IDRIVE_H
#define IDRIVE_H
#include "fileclass.h"
#include <list>
#include "DiskType.h"

class IDrive{

public:
    IDrive()
    {

    }

    virtual std::list<FileClass> showFileList() =0;
    virtual bool isEnoughSpace(float size) = 0;
    virtual void addFile(FileClass file) = 0;
    virtual void deleteFile(FileClass file) = 0;

protected:
    float AllCapacity;
    float usedCapacity;
    std::list<FileClass> fileLists;
    diskTypes_struct types;

};

#endif // IDRIVE_H
