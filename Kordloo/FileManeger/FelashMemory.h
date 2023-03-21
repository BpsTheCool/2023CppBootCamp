#ifndef FELASHMEMORY_H
#define FELASHMEMORY_H
#include "Divice.h"
#include "File.h"


class FelashMemory : public Divice , public File
{
public:
    FelashMemory(std::string type);
    FelashMemory(std::string name , int size);
};

#endif // FELASHMEMORY_H
