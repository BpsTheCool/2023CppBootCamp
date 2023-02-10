#include "TextFile.h"

std::string TextFile::read()
{
    return this->getContent();
}

void TextFile::write(std::string content)
{
    this->setContent(content);
}

