#pragma once
#include "Device.h"
#include <string>

class CD : public Device
{
public:
	CD(std::string name) : Device("CD_" + name, 16) {}

	void formatDevice() override;
	void newFile(std::string) override;
	void deleteFile(int) override;
	TextFile& getAccess(int) override;
};

