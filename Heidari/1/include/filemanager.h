#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <list>
#include "idrivewrapper.h"

class FileManager
{
private:
 IDriveWrapper driveWrapper;
public:
    FileManager();
    void addInternalHDD();
    void addFileToHdd(FileClass file);
    void deleteFileOfHdd();
};

#endif // FILEMANAGER_H
