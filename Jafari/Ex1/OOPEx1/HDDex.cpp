#include "includes/HDDex.h"


HDDex::HDDex(int storage, bool isReadOnly)
    : m_storage(storage), m_isReadOnly(isReadOnly), m_edjectStatus(false)
{
    qDebug()<< "External hard created!";
}

int HDDex::getStorage()
{
    return m_storage;
}

void HDDex::read()
{
    if (m_edjectStatus)
        qDebug()<< "Cant read, External hard edjected!";
    else
        qDebug()<< "Reading from External hard...";
}

void HDDex::write()
{
    if (m_edjectStatus)
        qDebug()<< "Cant write, External hard edjected!";
    else {
        if (m_isReadOnly)
            qDebug()<< "External hard is readonly!";
        else
            qDebug()<< "Writing to External hard...";
    }
}

void HDDex::edject(bool status)
{
    if (status)
        qDebug()<< "HDD Edject";
    else
        qDebug()<< "HDD Insert!";
    m_edjectStatus = status;
}
