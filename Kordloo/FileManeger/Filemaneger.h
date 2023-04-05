#ifndef FILEMANEGER_H
#define FILEMANEGER_H
#include <vector>
#include <memory>

class Divice;
class File;

class FileManeger
{
    std::vector<std::shared_ptr<Divice>> m_divicelist;


public:
    FileManeger();

    void setName(std::shared_ptr<Divice> newName);
    void showdivices();
    void removedivice(std::string div);
};

#endif // FILEMANEGER_H
