#include "HDD.h"
#include <iostream>

void HDD::formatDevice()
{
	this->deviceStorage = 64;
	this->deviceFiles.clear();
	std::cout << "Successfully formated! press any key to continue.";
}

void HDD::newFile(std::string name)
{
	TextFile temp(name);
	deviceFiles.push_back(temp);
	allocateSpace(4);
}

void HDD::deleteFile(int index)
{
	this->deviceFiles.erase(deviceFiles.begin() + index);
	this->freeSpace(4);
}

TextFile& HDD::getAccess(int index)
{
	return deviceFiles.at(index);
}
