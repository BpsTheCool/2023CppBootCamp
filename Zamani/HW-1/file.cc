//
//  file.cpp
//  os_file_manager_model
//
//  Created by alireza on 11/1/1401 AP.
//

#include "file.h"


file::file()
{
    m_name = "new_file";
    m_extension = ".txt";
    m_size = 0;
    m_permission = 6;
}

file::file(std::string name,std::string ext, int size, int permission)
{
    m_name = name;
    m_extension = ext;
    m_size = size;
    m_permission = permission;
}
//file::file(file &to_copy)
//{
//    m_name = to_copy.get_name();
//    m_extension = to_copy.get_extension();
//    m_size = to_copy.get_size();
//    m_permission = to_copy.get_permission();
//}

void file::get_info()
{
    std::cout << m_name + m_extension << '\n';
}
