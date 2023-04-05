#include "../include/fileclass.h"

FileClass::FileClass()
{

}

/*********************************************************************************************/
void FileClass::setFileSize(float val)
{
    _fileSize = val;
}

/*********************************************************************************************/
float FileClass::getFileSize()
{
    return _fileSize;
}

/*********************************************************************************************/
void FileClass::setFileName(std::string val)
{
    _fileName = val;
}

/*********************************************************************************************/
std::string FileClass::getFileName()
{
    return _fileName;
}
