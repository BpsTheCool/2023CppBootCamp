#ifndef STORAGES_H
#define STORAGES_H

#include <iostream>
#include <QObject>
#include <vector>
#include <string>
#include "file.h"

class Storages : public QObject
{
    Q_OBJECT

    std::vector <File*> m_files;
    double total_size;
    void setTotal_size(double newTotal_size);
protected:
    MessageAndErrors message_errors;
    bool writableStorage;
    bool ejectable;
    bool ejected;
    bool inserted;
    int free_space;
    QString m_type;
public:
    explicit Storages(QObject *parent = nullptr,
                      QString storagename="",
                      double totalspace=100,
                      bool ejectable=false,
                      bool IsWritable=true
            );
    QString storage_name;
    void listFiles();
    void createNewFile(QString file_name,
                       bool Isreadble=true,
                       bool Iswritble=true,
                       bool Isexcutble=true,
                       QString contents="empty");
    void deleteFile(QString file_name);
    void changeFile(QString thisFile,
                    QString new_file_name,
                    bool new_Isreadble,
                    bool new_Iswritble,
                    bool new_Isexcutble,
                    QString new_contents
                    );
    void ReadFile(QString FileName);
    double getTotal_size() const;
    void clear();
    QString get_m_type() const;
    ~Storages();
    virtual void eject() = 0;
    virtual void insert() = 0;

    bool getEjectable() const;
    void setEjectable(bool newEjectable);

    bool getEjected() const;
    void setEjected(bool newEjected);

signals:

    void fileDeleted(QString deletedFile);
    void fileCreated(QString file_name,QString storage_name);
};

#endif // STORAGES_H
