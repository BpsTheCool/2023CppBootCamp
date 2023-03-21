#include "Divice.h"
#include "File.h"
#include <iostream>

std::string Divice::type() const
{
    return m_type;
}

void Divice::showfiles()
{
    std::cerr<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
    for (auto &item : m_file) {

        std::cerr<<item<<"-"<<item->name()<<"\t"<<item->size()<<"\t\n";

    }
    std::cerr<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
}

void Divice::setFile(std::shared_ptr<File> newFile)
{
    m_file.emplace_back(newFile);
}

void Divice::uifile()
{
    std::cerr<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
    std::cerr<<"             pleas insert your command:\n";
    std::cerr<<" help ==> addFile   renameFile   deletFile   goBack\n";
    std::cerr<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
}



Divice::Divice()
{

}

Divice::Divice(std::string type)
    :m_type(type)
{

}
