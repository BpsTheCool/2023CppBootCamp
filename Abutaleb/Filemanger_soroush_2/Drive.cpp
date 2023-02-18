#include "Drive.h"

std::string Drive::namedrive() const
{
    return m_namedrive;
}

void Drive::setNamedrive(const std::string &newNamedrive)
{
    m_namedrive = newNamedrive;
}

int Drive::sizedrive() const
{
    return m_sizedrive;
}

void Drive::setSizedrive(int newSizedrive)
{
    m_sizedrive = newSizedrive;
}

Drive::Drive(std::string name, int size)
    :m_namedrive(name) , m_sizedrive(size)
{

}
