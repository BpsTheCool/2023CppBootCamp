#include "../include/idrivewrapper.h"

IDriveWrapper::IDriveWrapper()
{

}

/*********************************************************************************************/
void IDriveWrapper::addDrive(diskTypes_struct type)
{
   if(type.isReable|type.isWritable|!type.isRemovable)
   {
     HddInternal hdd ;
     hdd.setCapacity(124);
    // hdd = new HddInternal();  ?? why i cant create new
     allHDDDrivesList.push_back(hdd);
   }
}

/*********************************************************************************************/
void IDriveWrapper::removeDrive(diskTypes_struct type)
{
    if(type.isReable|type.isWritable|type.isRemovable)
    {

    }
}

/*********************************************************************************************/
void IDriveWrapper::addFile(FileClass file)
{
      auto lastHdd  = allHDDDrivesList.back();
      lastHdd.addFile(file);
}

