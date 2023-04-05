#include "file.h"
#include "messageanderrors.h"
File::File(QObject *parent,
           QString name,
           bool readble,
           bool writable,
           bool executable,
           QString content):
     m_size(sizeof(this)),
     m_name(name),
     m_readble(readble),
     m_writable(writable),
     m_executable(executable),
     m_content(content)
{

    QObject::connect(this,&File::unreadbleFile,
                     &message_errors,&MessageAndErrors::unReadbleFile);
    QObject::connect(this,&File::unwritableFile,
                     &message_errors,&MessageAndErrors::unWritable);
    QObject::connect(this,&File::unExecutableFile,
                     &message_errors,&MessageAndErrors::unExecutble);
};

void File::show(){
    QString r = m_readble ? "r" : "-";
    QString w = m_writable ? "w" : "-";
    QString x = m_executable ? "x" : "-";
    qInfo() << r+w+x+" "+ m_name + " " + QString::number(sizeof(*this));
}

void File::read(){
    if(m_readble==false){
        emit unreadbleFile(this->m_name);
    }
    else{
        qInfo()<<"content of "+m_name +": "+m_content;
    }
}

void File::write(QString newcontent){
    if(m_readble==false)
        emit unwritableFile(this->m_name);
    else{
        m_content = newcontent;
        qInfo()<<"file wrote succasfully!";
    }
}

void File::execute(){
    if(m_executable==false){
        emit unExecutableFile(this->m_name);
    } else {
        qInfo()<<"file Executed";
    }
}

double File::get_size() const
{
    return sizeof(*this);
}

QString File::name() const
{
    return m_name;
}

void File::setName(QString name)
{
    m_name = name;
}

bool File::readble() const
{
    return m_readble;
}

void File::setReadble(bool readble)
{
    m_readble = readble;
}

bool File::writable() const
{
    return m_writable;
}

void File::setWritable(bool newWritable)
{
    m_writable = newWritable;
}

bool File::executable() const
{
    return m_executable;
}

void File::setExecutable(bool newExecutable)
{
    m_executable = newExecutable;
}

const QString &File::content() const
{
    return m_content;
}

void File::setContent(const QString newContent)
{
    m_content = newContent;
}

File::~File(){
    qInfo()<<"file deconstructed";
}

