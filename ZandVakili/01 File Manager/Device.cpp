#include "Device.h"
#include <iostream>

std::string Device::getDeviceName()
{
	return deviceName;
}

int Device::getDeviceStorage()
{
	return deviceStorage;
}

void Device::freeSpace(int space)
{
	this->deviceStorage += space;
}

void Device::allocateSpace(int space)
{
	this->deviceStorage -= space;
}


void Device::printFilesList()
{
	std::cout << "------------" << std::endl;
	std::cout << "Files : " << std::endl;
	for (int i = 0; i < deviceFiles.size(); i++)
	{
		std::cout << i + 1 << ". " << deviceFiles.at(i).getName()
				  << deviceFiles.at(i).getExtension() << "  "
				  << deviceFiles.at(i).getSize() << "Mb" << '\n';
	}
	std::cout << "------------" << std::endl;
}
