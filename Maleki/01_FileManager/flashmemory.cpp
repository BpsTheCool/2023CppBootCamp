#include "flashmemory.h"

FlashMemory::FlashMemory(QObject *parent,
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
    ++countFlashMemory;
    setName();
    setType();
}
void FlashMemory::setName(){
    storage_name="Flash"+QString::number(countFlashMemory);
}
void FlashMemory::eject() {
    ejected=true;
    inserted=false;
    qInfo()<<"FlashMemory ejected";
}
void FlashMemory::insert() {
    ejected=false;
    inserted=true;
    qInfo()<<"FlashMemory inserted";
}
void FlashMemory::setType(){
    m_type="FlashMemory";
}

void FlashMemory::setName(QString name){
    storage_name=name;
}
