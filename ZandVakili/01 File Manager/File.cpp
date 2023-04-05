#include "File.h"

std::string File::getName()
{
    return fileName;
}

std::string File::getExtension()
{
    return fileExtension;
}

int File::getSize()
{
    return fileSize;
}

void File::rename(std::string newName)
{
    this->fileName = newName;
}

void File::clear()
{
    this->fileContent = "";
}

std::string File::getContent()
{
    return fileContent;
}

void File::setContent(std::string content)
{
    fileContent = content;
}
