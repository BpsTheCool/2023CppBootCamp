#include "storages.h"
#include "file.h"

double Storages::getTotal_size() const
{
    return total_size;
}

void Storages::setTotal_size(double newTotal_size)
{
    total_size = newTotal_size;
}

bool Storages::getEjected() const
{
    return ejected;
}

void Storages::setEjected(bool newEjected)
{
    ejected = newEjected;
}

bool Storages::getEjectable() const
{
    return ejectable;
}

void Storages::setEjectable(bool newEjectable)
{
    ejectable = newEjectable;
}

Storages::Storages(QObject *parent,
                   QString storagename,
                   double totalspace,
                   bool ejectable,
                   bool IsWritable)
    : QObject{parent},
      storage_name(storagename),
      total_size(totalspace),
      writableStorage(IsWritable)
{
      QObject::connect(this,&Storages::fileDeleted,
                         &message_errors,&MessageAndErrors::fileDeleted);
      QObject::connect(this,&Storages::fileCreated,
                       &message_errors,&MessageAndErrors::fileCreated);
}

void Storages::listFiles()
{   free_space=getTotal_size();
    for(int i=0;i<m_files.size();i++)
        free_space -= m_files[i]->get_size();
    qInfo()<<Qt::endl<<"list of "+this->storage_name+" storage["+get_m_type()+"] (totalsize:"
          <<getTotal_size() <<",Free space:"<<this->free_space<<")";
    if(getEjected()==true){
        qInfo()<<"this sorage is ejacted";
    } else{
        for(int i=0;i<m_files.size();i++)
            m_files[i]->show();
    }

}

void Storages::createNewFile(QString file_name,
                             bool Isreadble,
                             bool Iswritble,
                             bool Isexcutble,
                             QString contents){
    bool unique=true;
    for(int i=0;i<m_files.size();i++){
        if(file_name==m_files[i]->name()){
            qInfo()<<"there is a file with same name ("+file_name+")";
            unique=false;
            break;
        }
    }
    if(unique==true){
        File* newFile =new File(nullptr,
                                file_name,
                                Isreadble,
                                Iswritble,
                                Isexcutble,
                                contents);
        free_space=getTotal_size();
        for(int i=0;i<m_files.size();i++)
            free_space -= m_files[i]->get_size();
        if(free_space<=sizeof(*newFile)){
            delete newFile;
            qInfo()<<"this Storage have not enough space!";
            return;
        }else{
            m_files.push_back(newFile);
            emit fileCreated(file_name,this->storage_name);
        }
    }

}

void Storages::deleteFile(QString file_name){
    bool ThereIsTheFile=false;
    for(int i=0 ; i<m_files.size() ; i++)
        if(m_files[i]->name() ==file_name){
            delete m_files[i];
            m_files.erase(m_files.begin()+i);
            emit fileDeleted(file_name);
            ThereIsTheFile=true;
            break;
        }
    if(ThereIsTheFile==false){
        qInfo()<<"There Is NOT file named (" +file_name +") in storage";
    };

}

void Storages::changeFile(QString thisFile,
                QString new_file_name,
                bool new_Isreadble,
                bool new_Iswritble,
                bool new_Isexcutble,
                QString new_contents
                ){
    if(writableStorage==false){
        qInfo()<<"this Storage is not ReWritable";
        return;
    }
    bool unique=true;
    for(int i=0;i<m_files.size();i++){
        if(new_file_name==m_files[i]->name()){
            qInfo()<<"can't change name, there is a file with same name ("+new_file_name+")";
            unique=false;
            break;
        }
    }

    bool isThereFile=false;
    if(unique){
        for(int i=0;i<m_files.size();i++){
            if(thisFile==m_files[i]->name()){
                m_files[i]->setName(new_file_name);
                qInfo()<<"file name changed";
                m_files[i]->setReadble(new_Isreadble);
                qInfo()<<"file r changed";
                m_files[i]->setWritable(new_Iswritble);
                qInfo()<<"file w changed";
                m_files[i]->setExecutable(new_Isexcutble);
                qInfo()<<"file x changed";
                isThereFile=true;
                break;
            }
        }
        if(!isThereFile){
            qInfo()<<"There Is No File With that Name";
        }
    }
}
void Storages::ReadFile(QString FileName){
    bool notSuchFile=true;
    for(int i=0;i<m_files.size();i++){
        if(m_files[i]->name() ==FileName){
            m_files[i]->read();
            notSuchFile=false;
        }
    }
    if(notSuchFile==true){
        qInfo()<<"No such File ("+FileName+") in Storage";
    };

}
void Storages::clear(){
    for(int i=0;i<m_files.size();i++){
        delete m_files[i];
    }
    m_files.erase(m_files.begin(),m_files.end());
}
Storages::~Storages(){
    clear();
    qInfo()<<"storage decunstructed!";
};
QString Storages::get_m_type() const {
    return m_type;
}
