#include "storage.h"
#include <vector>

void Devices::listFiles()
{
    for(int i=0;i<m_files.size();i++)
        m_files[i].show();
}

void Devices::createNewFile(){
    std::string file_name_temp;
    QString file_name;
    bool unique;
    do {
        qInfo()<<"\nfile name?";
        unique=true;
        std::cin>>file_name_temp;
        file_name=QString::fromStdString(file_name_temp);

        for(int i=1;i<m_files.size();i++)
            if(file_name==m_files[i].name()){
                qInfo()<<"there is a file with same name";
                unique=false;
                qInfo()<<"try again; give me a file Name:";
                break;
            }

    }while(!unique);
    m_files.push_back( File (nullptr,
                                file_name,
                                default_readble_file,
                                default_writble_file,
                                default_excutble_file,
                                "empty file"));
}
