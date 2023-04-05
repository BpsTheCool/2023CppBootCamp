#ifndef CD_H
#define CD_H
#include "Divice.h"
#include <string>
#include "File.h"


class Cd : public Divice , public File
{
public:
    Cd(std::string type);
    Cd(std::string name, int size);
};

#endif // CD_H
