#include "cdrom.h"

CdRom::CdRom(QObject *parent,
                     QString storagename,
                     double totalspace,
                     bool ejectable,
                     bool IsWritable):
                     Storages(parent,
                             storagename,
                             totalspace,
                             ejectable,
                             IsWritable)
{
    ++countCdRom;
    setName();
    setType();
}
void CdRom::eject() {
    if(ejectable){
        ejected=true;
        inserted=false;
        qInfo()<<"CdRom ejected";
    } else {
        qInfo()<<"this Storage Is Not ejectable";
    }
}
void CdRom::insert()  {
    ejected=false;
    inserted=true;
    qInfo()<<"CdRom inserted";
}
void CdRom::setType(){
    m_type="CdRom";
}

void CdRom::setName(QString name){
    storage_name=name;
}
