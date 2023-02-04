#include "../include/hddinternal.h"


HddInternal::HddInternal()
{
    types.isReable =  true;
    types.isRemovable = false;
    types.isWritable = true;

}

/*********************************************************************************************/
bool HddInternal::isEnoughSpace(float size)
{
  if(AllCapacity - usedCapacity >= size)
  {
      return true;
  }
  return false;
}

/*********************************************************************************************/
std::list<FileClass> HddInternal::showFileList()
{
  if(fileLists.size()>0)
  {
      return fileLists;
  }
  return {};
}

/*********************************************************************************************/
void HddInternal::addFile(FileClass file)
{
    if(isEnoughSpace(file.getFileSize()))
    {
      fileLists.push_back(file);
    }
   std::cout << "there is not enough space" << std::endl;
   std::cin.get();
}

/*********************************************************************************************/
void HddInternal::deleteFile(FileClass file)
{
//    for (auto i = fileLists.begin(); i!= fileLists.end(); i++){
//          if(i->getFileName() == file.getFileName())
//          {
//              fileLists.remove(*i);
//          }
//    }
}

/*********************************************************************************************/
void HddInternal::setCapacity(float val)
{
    AllCapacity = val;
}

/*********************************************************************************************/
float HddInternal::getCapacity()
{
     return AllCapacity;
}
