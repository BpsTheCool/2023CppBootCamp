//
//  device.cpp
//  os_file_manager_model
//
//  Created by alireza on 11/1/1401 AP.
//

#include "device.h"


device::device(int size, std::string name, std::string type) 
{
    m_capacity = size;
    m_name = name;
    m_type = type;
};


disk_drive::disk_drive(int size , std::string name, std::string type)
: device(size,name,type)
{
    std::cout << "removable device : " << name << " of size : " << size << " crated! \n" ;
}

void disk_drive::write(file &f)
{
    if (f.get_size() <= m_capacity)
    {
        storage.emplace_back(f);
        for (int i = 0; i < storage.size(); i++)
        {
             m_capacity -= storage[i].get_size();
        }

    }
    else
        std::cout << "not enough space!!! \n" ;
    
}

file *disk_drive::read(int file_index)
{
    return &storage[file_index];
}

void disk_drive::erase(int file_index)
{
    
    storage.erase(storage.begin()+file_index);
}

