#ifndef HDD_H
#define HDD_H
#include "Divice.h"
#include "File.h"
#include <string>

class Hdd : public Divice , public File
{

public:
    Hdd();
    Hdd(std::string type);
    Hdd(std::string name,int size);
};

#endif // HDD_H
