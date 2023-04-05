#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include "storages.h"
#include <vector>

class FileManager : public QObject
{
    Q_OBJECT
    std::vector <Storages*> allStorages;
public:
    explicit FileManager(QObject *parent = nullptr);
    Storages* use(QString storage);
    void Insert(Storages *S);
    void listAllStorages();
    void eject(QString storage);
signals:

};

#endif // FILEMANAGER_H
