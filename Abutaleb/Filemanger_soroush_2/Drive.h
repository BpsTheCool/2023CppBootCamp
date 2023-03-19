#ifndef DRIVE_H
#define DRIVE_H

#include <string>


class Drive
{
    std::string m_namedrive;
    int m_sizedrive;

public:
    Drive(std::string name , int size);
    std::string namedrive() const;
    void setNamedrive(const std::string &newNamedrive);
    int sizedrive() const;
    void setSizedrive(int newSizedrive);
};

#endif // DRIVE_H
