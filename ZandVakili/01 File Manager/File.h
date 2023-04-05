#pragma once
#include <string>

class File
{
	std::string fileName;
	std::string fileExtension;
	std::string fileContent;
	int fileSize;
public:
	File() 
		: fileName("Unknown"), fileExtension(""), fileSize(0) {}

	File(std::string name, std::string extension, int size)
		: fileName(name), fileExtension('.' + extension), fileSize(size) {}
	//
	std::string getName();
	std::string getExtension();
	int getSize();
	//
	void rename(std::string);
	//
	virtual std::string read() = 0;
	virtual void write(std::string) = 0;
	void clear();
protected:
	std::string getContent();
	void setContent(std::string);
};