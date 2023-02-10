#include "filemanager.h"

FileManager::FileManager(QObject *parent)
    : QObject{parent}
{

}
Storages* FileManager::use(QString storage){
    for(int i=0;i<allStorages.size();i++)
        if(allStorages[i]->storage_name==storage){
            return allStorages[i];
        }
    qInfo()<<"there Is NoT Such a Storage";
    return 0;
}
void FileManager::Insert(Storages *S){
    bool Saved=false;
    for(int i=0;i<allStorages.size();i++)
        if(allStorages[i]->storage_name==S->storage_name){
            Saved=true;
            if(allStorages[i]->getEjected()){
                allStorages[i]->setEjected(false);
                qInfo()<<"Storage Inserted again";
            }else{
                qInfo()<<"this Storage has been Inserted before";
            }
            break;
        }
    if(!Saved){
        allStorages.push_back(S);
        qInfo()<<"Storage Inserted succassfully";
        S->insert();
    }
}
void FileManager::listAllStorages(){
    for(int i=0;i<allStorages.size();i++){
        allStorages[i]->listFiles();
    }
}
void FileManager::eject(QString storage){
    bool find=false;
    for(int i=0;i<allStorages.size();i++){
        if(allStorages[i]->storage_name==storage){
            if(allStorages[i]->getEjectable()){
                allStorages[i]->setEjected(true);
                qInfo()<<"storage Ejected";
            }else{
                qInfo()<<"this Storage is not ejectable";
            }
            find=true;
            break;
        }
    }
    if(!find){
        qInfo()<<"there Is NoT Such a Storage";
    }
}
