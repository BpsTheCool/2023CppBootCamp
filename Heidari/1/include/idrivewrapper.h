#ifndef IDRIVEWRAPPER_H
#define IDRIVEWRAPPER_H
#include "IDrive.h"
#include "DiskType.h"
#include "hddinternal.h"

class IDriveWrapper
{
public:
     std::list<HddInternal> allHDDDrivesList;

    IDriveWrapper();
    void addDrive(diskTypes_struct type);
    void removeDrive(diskTypes_struct type);
    void addFile(FileClass file);
};

#endif // IDRIVEWRAPPER_H
