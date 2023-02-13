#include <iostream>
#include <sstream>
#include "sharedptr.h"

sasan::Sharedptr::Sharedptr(int *ptr)
    : hData(ptr)
    , accessCount(new int(1))
{
    std::cout << "The shared pointer " << hData << " has been constructed!" << std::endl;
    std::cout << "Total number of copies: " << (*accessCount) << std::endl;
}

sasan::Sharedptr::~Sharedptr()
{
    if((*accessCount) > 0)
    {
        std::cout << "The shared pointer " << hData << " has been de-constructed!" << std::endl;
        (*accessCount)--;
        std::cout << "Total number of copies: " << (*accessCount) << std::endl;
        // delete actual pointers
        if((*accessCount) == 0)
        {
            std::cout << "The shared pointer " << hData << " has been deleted successfuly!" << std::endl;
            delete hData;
            delete accessCount;
        }
    }
}

// Copy Constructor
sasan::Sharedptr::Sharedptr(Sharedptr& copiedFrom)
    : hData(copiedFrom.hData)
    , accessCount(copiedFrom.accessCount)
{
    (*accessCount)++;
    std::cout << "Copy constructor has been invoked to make a copy from " << toString() << std::endl;
    std::cout << "Total number of copies: " << (*accessCount) << std::endl;
}
// Move Constructor
sasan::Sharedptr::Sharedptr(Sharedptr&& movedFrom)
    : hData(movedFrom.hData)
    , accessCount(movedFrom.accessCount)
{
    std::cout << "Move constructor has been invoked to accept a move from " << toString() << std::endl;
    std::cout << "Total number of copies: " << (*accessCount) << std::endl;

    movedFrom.reset();

    std::cout << "\nThe moved shared pointer " << &movedFrom << " is now pointing to an invalid address" << std::endl;
    std::cout << "and it has been reset!" << std::endl;
}
// Reset function
void sasan::Sharedptr::reset()
{
    hData = nullptr;
    accessCount = nullptr;
}
// To String function
std::string sasan::Sharedptr::toString() const
{
    std::ostringstream ss;
    ss << "Address: " << hData;
    return std::string(ss.str());
}
// Mimicking a de-referencing star operator on Sharedptr object
int& sasan::Sharedptr::operator *()
{
    return *hData;
}
// Assignment operator
sasan::Sharedptr& sasan::Sharedptr::operator =(const Sharedptr& assignedFrom)
{
    this->~Sharedptr();
    hData = assignedFrom.hData;
    accessCount = assignedFrom.accessCount;
}

int* sasan::make_shared(int input)
{
    return new int(input);
}
