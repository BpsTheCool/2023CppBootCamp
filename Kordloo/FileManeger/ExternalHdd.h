#ifndef EXTERNALHDD_H
#define EXTERNALHDD_H
#include"Divice.h"
#include"File.h"

class ExternalHdd: public Divice,public File
{
public:
    ExternalHdd(std::string type);
    ExternalHdd(std::string name , int size);
};

#endif // EXTERNALHDD_H
