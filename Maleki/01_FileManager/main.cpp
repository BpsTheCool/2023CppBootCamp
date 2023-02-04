#include <QCoreApplication>
#include <vector>
#include <iostream>
#include "filemanager.h"
#include "flashmemory.h"
#include "storages.h"
#include "cdrom.h"
#include <string>
#include <array>
#include <QTextStream>

int FlashMemory::countFlashMemory=0;
int CdRom::countCdRom=0;

void wrong_command(){
    qInfo()<<"wrong command!";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    FlashMemory ab(&a,"storage1",350,true,true);
    ab.createNewFile("File1");
    ab.createNewFile("File2",false);
    ab.createNewFile("File3",true,false);
    ab.createNewFile("File3",true,true,false);
    ab.createNewFile("File4",true,true,false);
    ab.createNewFile("File5",true,true,false,"Hello world");
    ab.createNewFile("File6",true,true,false,"Hello world");
    FlashMemory ac(&a,"storage1",350,true,true);
    ac.createNewFile("File1");
    ac.createNewFile("File2",false);
    ac.createNewFile("File3",true,false);
    ac.createNewFile("File3",true,true,false);
    ac.createNewFile("File4",true,true,false);
    ac.createNewFile("File5",true,true,false,"Hello world");
    ac.createNewFile("File6",true,true,false,"Hello world");
    CdRom ad(&a,"storage1",350,true,true);
    ad.createNewFile("File1");
    ad.createNewFile("File2",false);
    ad.createNewFile("File3",true,false);
    ad.createNewFile("File3",true,true,false);
    ad.createNewFile("File4",true,true,false);
    ad.createNewFile("File5",true,true,false,"Hello world");
    ad.createNewFile("File6",true,true,false,"Hello world");

    ab.listFiles();
    qInfo()<<Qt::endl;

    ab.ReadFile("File2");
    ab.ReadFile("File5");
    ab.ReadFile("File7");

    qInfo()<<Qt::endl;
    ab.deleteFile("File4");
    ab.deleteFile("File4");

    ab.listFiles();

    qInfo()<<Qt::endl;
    ab.changeFile("File1","File2",false,false,false,"name");
    ab.changeFile("File1","File7",false,false,false,"name");
    ab.changeFile("File8","File10",false,false,false,"name");

    ab.listFiles();

    ab.insert();
    Storages* s=static_cast<Storages*>(&ab);
    s->insert();
    FlashMemory* f=dynamic_cast<FlashMemory*>(s);
    f->insert();
    qInfo()<<f->get_m_type();

    FileManager FM;

    FM.Insert(&ab);
    FM.Insert(&ab);
    FM.Insert(&ac);
    FM.Insert(&ad);

    QStringList Command;


    while(true){
        std::cout<<"\n$type command:";
        QTextStream qtin(stdin);
        QString line= qtin.readLine().trimmed();
        Command= line.split(" ", Qt::SkipEmptyParts);
        if(Command.size()==0){
            wrong_command();
        }else
        {
            if(Command[0]=="list"){
                if(Command.size()==1)
                    FM.listAllStorages();
                else if (Command.size()==2){
                    if(FM.use(Command[1])){
                        FM.use(Command[1])->listFiles();
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            } else if(Command[0]=="create"){
                if (Command.size()==3){
                    if(FM.use(Command[1])){
                        FM.use(Command[1])->createNewFile(Command[2]);
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            } else if(Command[0]=="delete"){
                if (Command.size()==3){
                    if(FM.use(Command[1])){
                        FM.use(Command[1])->deleteFile(Command[2]);
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            } else if(Command[0]=="changeName"){
                if (Command.size()==4){
                    if(FM.use(Command[1])){
                        FM.use(Command[1])->changeFile(Command[2],Command[3],true,true,true,"new File");
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            }else if(Command[0]=="read"){
                if (Command.size()==3){
                    if(FM.use(Command[1])){
                        FM.use(Command[1])->ReadFile(Command[2]);
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            }else if(Command[0]=="clear"){
                if (Command.size()==2){
                    if(FM.use(Command[1])){
                        FM.use(Command[1])->clear();
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            } else if(Command[0]=="eject"){
                if (Command.size()==2){
                    if(FM.use(Command[1])){
                        FM.eject(Command[1]);
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            }else if(Command[0]=="exit"){
                if (Command.size()==1){
                    qInfo()<<"exit";
                    break;
                }else{
                    wrong_command();
                }

            } else if(Command[0]=="insert"){
                if (Command.size()==2){
                    if(FM.use(Command[1])){
                        FM.Insert(FM.use(Command[1]));
                    }
                    else
                        wrong_command();
                } else {
                    wrong_command();
                }
            } else{
                wrong_command();
            }
        }}
    return a.exec();
}
