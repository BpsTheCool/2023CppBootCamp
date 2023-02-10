#ifndef FILE_H
#define FILE_H

#include "QDebug"
#include <QObject>
#include <vector>
#include "MessageAndErrors.h"

class File : public QObject
{
    Q_OBJECT

private:

    MessageAndErrors message_errors;
    double m_size;
    QString m_name;
    bool m_readble;
    bool m_writable;
    bool m_executable;
    QString m_content;
    void setContent(const QString newContent);
    const QString &content() const;

public:
    explicit File(QObject *parent = nullptr,
                  QString name="",
                  bool readble=true,
                  bool writable=false,
                  bool executable=false,
                  QString content=""
                  );
    void show();
    void read();
    void write(QString newcontent);
    void execute();


    double get_size() const;

    QString name() const;
    void setName(QString name);

    bool readble() const;
    void setReadble(bool readble);

    bool writable() const;
    void setWritable(bool newWritable);

    bool executable() const;
    void setExecutable(bool newExecutable);

    ~File();

signals:
    void unreadbleFile(QString file_name);
    void unwritableFile(QString file_name);
    void unExecutableFile(QString file_name);

};

#endif // FILE_H
