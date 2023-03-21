#ifndef DIVICE_H
#define DIVICE_H
#include<vector>
#include<memory>
#include<string>

class File;



class Divice
{
    std::string m_type;
    std::vector<std::shared_ptr<File>> m_file;


public:
    Divice();
    Divice(std::string type);
    std::string type() const;
    void showfiles();
    void setFile(std::shared_ptr<File> newFile);
    void uifile();

};

#endif // DIVICE_H
