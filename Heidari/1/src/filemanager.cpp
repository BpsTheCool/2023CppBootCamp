#include "../include/filemanager.h"


FileManager::FileManager()
{


}

void FileManager::addInternalHDD()
{
    diskTypes_struct type;
    type.isReable = true;
    type.isRemovable = false;
    type.isWritable = true;
    driveWrapper.addDrive(type);
}

void FileManager::addFileToHdd(FileClass file)
{
   driveWrapper.addFile(file);
}
