#include "includes/Flash.h"


Flash::Flash(int storage, bool isReadOnly)
    : m_storage(storage), m_isReadOnly(isReadOnly), m_edjectStatus(false)
{
    qDebug()<< "Flash created!";
}

int Flash::getStorage()
{
    return m_storage;
}

void Flash::read()
{
    if (m_edjectStatus)
        qDebug()<< "Cant read, Flash edjected!";
    else
        qDebug()<< "Reading from Flash...";
}

void Flash::write()
{
    if (m_edjectStatus)
        qDebug()<< "Cant write, Flash edjected!";
    else {
        if (m_isReadOnly)
            qDebug()<< "Flash is readonly!";
        else
            qDebug()<< "Writing to Flash...";
    }
}

void Flash::edject(bool status)
{
    if (status)
        qDebug()<< "Flash Edject ";
    else
        qDebug()<< "Flash Insert ";
    m_edjectStatus = status;
}
