#pragma once
#include "File.h"

class TextFile : public File
{
public:
	TextFile(std::string name)
		: File(name, "txt", 4) {}
	std::string read() override;
	void write(std::string) override;
};
