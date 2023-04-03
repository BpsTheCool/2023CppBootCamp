#include "Filemaneger.h"
#include "Divice.h"
#include <iostream>
#include <algorithm>

void FileManeger::setName(std::shared_ptr<Divice> newName)
{
    m_divicelist.emplace_back(newName);
}

void FileManeger::showdivices()
{
    std::cerr<<"============================================\n";
    std::cerr<<"            useable divices                 \n";
    std::cerr<<"============================================\n"<<std::endl;
    for (auto &item : m_divicelist)
    {
        std::cerr <<item->type()<<"\t";
    }
    std::cerr<<std::endl;
    std::cerr<<"============================================\n"<<std::endl;
}

void FileManeger::removedivice(std::string div)
{
//    bool flag=false;
//    for(auto it=m_divicelist.begin() ; it !=m_divicelist.end() ; )
//    {
//        if((*it)->type()==div)
//        {
//            m_divicelist.erase(it);
//            flag=true;
//            break;
//        }
//        else
//        {
//            it++;
//        }
//    }

//    if(flag==false)
//    std::cerr << "error" << std::endl;
//    int x;
//    std::cin >> x;
//    for (auto &item : m_divicelist) {
//        if(item->type()==div)
//        {
//            auto it = std::find(m_divicelist.begin(),m_divicelist.end(),item);
//            m_divicelist.erase(it);
//        }
//    }

    m_divicelist.erase(std::remove_if(m_divicelist.begin(),m_divicelist.end(),[&](std::shared_ptr<Divice> i){return i->type()==div;}));
}



FileManeger::FileManeger()
{
 //std::cerr<<"\tpleas add your divice\n";
}

