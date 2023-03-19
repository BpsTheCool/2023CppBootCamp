#include "CD.h"
#include <iostream>

void CD::formatDevice()
{
	std::cout << "CD cannot be formated! press any key to continue.";
}

void CD::newFile(std::string name)
{
	TextFile temp(name);
	deviceFiles.push_back(temp);
	allocateSpace(4);
}

void CD::deleteFile(int)
{
	std::cout << "You cannot delete a file from CD.";
}

TextFile& CD::getAccess(int index)
{
	return deviceFiles.at(index);
}