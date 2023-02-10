#ifndef STORAGE_H
#define STORAGE_H


#include <iostream>
#include "file.h"
#include <QObject>
#include <vector>
#include <string>
#include "MessageAndErrors.h"

class Storage : public QObject
{
    Q_OBJECT

    MessageAndErrors message_errors;
    std::vector <File> m_files;
    QString storage_name;
    int total_size;
    int free_space;
    bool writabledisk;
    bool default_readble_file;
    bool default_writble_file;
    bool default_excutble_file;
    File configuration;

public:
    explicit Storage(QObject *parent = nullptr , QString storagename="NoName");

    void createNewFile();
    void listFiles();
//    void deleteFile(QString deleteName){
//        for(int i=1 ; i<m_files.size() ; i++)
//            if(m_files[i].name() ==deleteName){
//                emit fileDeleted(m_files[i].name());
//                m_files.erase(m_files.begin()+i);
//                break;
//            }
//    };

    //    void moveFile();
    //    void renameFile();
    //    void duplicateFile();


    const std::vector<File> &files() const;
    void setFiles(const std::vector<File> &newFiles);

signals:
    void fileDeleted(QString deletedFile);


};

#endif // STORAGE_H
