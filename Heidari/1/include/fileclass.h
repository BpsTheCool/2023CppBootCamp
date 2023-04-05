#ifndef FILECLASS_H
#define FILECLASS_H
#include <iostream>

class FileClass
{
    float _fileSize;
    std::string _fileName;
public:
    FileClass();

    void setFileSize(float val);
    float getFileSize();

    void setFileName(std::string val);
    std::string getFileName();
};

#endif // FILECLASS_H
