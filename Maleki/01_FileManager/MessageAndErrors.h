#ifndef MESSAGEANDERRORS_H
#define MESSAGEANDERRORS_H

#include <QObject>
#include <QDebug>

class MessageAndErrors : public QObject
{
    Q_OBJECT
public:
    explicit MessageAndErrors(QObject *parent = nullptr){};

signals:


public slots:
    void unReadbleFile(QString file_name){
        qInfo()<<"This File ("+file_name+") IS Unreadble";
    }
    void unWritable(QString file_name){
        qInfo()<<"This File ("+file_name+") IS unWritable";
    }
    void unExecutble(QString file_name){
        qInfo()<<"This File ("+file_name+") IS unExecutble";
    }
    void fileDeleted(QString file_name){
        qInfo()<<"File ("+file_name+") Deleted";
    }
    void fileCreated(QString file_name,QString storage_name){
        qInfo()<<"File "+file_name+" created in " + storage_name + " storage";
    }

};
#endif // MESSAGEANDERRORS_H
