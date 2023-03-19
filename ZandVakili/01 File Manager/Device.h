#pragma once
#include "TextFile.h"
#include <vector>
#include <string>


class Device
{
	std::string deviceName;
	static inline int  i = 0;
protected:
	int deviceStorage;
	std::vector <TextFile> deviceFiles;
public:
	// Constructor
	Device(std::string name, int storage)
		: deviceName(name), deviceStorage(storage){}
	// Getters
	std::string getDeviceName();
	int getDeviceStorage();
	// Memory
	void freeSpace(int);
	void allocateSpace(int);
	// 
	void printFilesList();
	virtual void formatDevice() = 0;
	virtual void newFile(std::string) = 0;
	virtual void deleteFile(int) = 0;
	virtual TextFile& getAccess(int) = 0;

};
