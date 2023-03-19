#pragma once
#include "Device.h"
#include <string>

class HDD : public Device
{
public:
	HDD(std::string name) : Device("HDD_" + name, 64) {}
	void formatDevice() override;
	void newFile(std::string) override;
	void deleteFile(int) override;
	TextFile& getAccess(int) override;
};

