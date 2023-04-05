
#include "file_manager.h"

file_manager::file_manager()
{
    m_internal = new disk_drive(2000,"01","non-removable");
}

void file_manager::mount(device *flash_drive)
{
    m_removable = flash_drive;
}

void file_manager::save_to_internal(file &f)
{
    
    m_internal->write(f);
}
void file_manager::save_to_external(file &f)
{
    
    m_removable->write(f);
}

void file_manager::show_capacity()
{
    std::cout << "remaining capacity: " << m_internal->get_size() << "MB " << "in " << m_internal->get_name() << '\n';
    if (m_removable != nullptr) {
        std::cout << "remaining capacity: " << m_removable->get_size() << "MB " << "in " << m_removable->get_name() << '\n';
    }
}

void file_manager::search(std::string filename)
{
    for (int i = 0; i < m_internal->items_count(); i++) {
        if(filename == m_internal->read(i)->get_name())
            std::cout << "file found at internal storage! \n";
            
    }
    if (m_removable != nullptr) {
        for (int i = 0; i < m_removable->items_count(); i++) {
            if(filename == m_removable->read(i)->get_name())
                std::cout << "file found at external storage! \n";
        }
    }
}
void file_manager::create_file()
{
    std::string file_name;
    std::cout<<"enter your file name: \n" ;
    std::cin >>file_name;
    int size;
    std::cout<<"enter your file size (MB): \n" ;
    std::cin >>size;
    std::string type;
    std::cout<<"enter your file type (extension): \n" ;
    std::cin >>type;
    int permission;
    std::cout<<"enter your file permission : \n " << "(read-only = 4 / read-write = 6) \n" ;
    std::cin >>permission;
    std::string location;
    std::cout<<"enter saving location: \n" ;
    std::cin >>location;
    
    
    file temp(file_name,type,size,permission);
    if(location == "internal")
    save_to_internal(temp);
    else
        if(m_removable != nullptr)
        save_to_external(temp);
        else
            std::cout<<" failed!! please mount your external memory and try again!! \n";
}

void file_manager::show_all_files()
{
    std::cout << "@" << m_internal->get_name() << ":";
    for (int i = 0; i < m_internal->items_count(); i++) {
        std::cout << i << "-" << m_internal->read(i)->get_name() <<m_internal->read(i)->get_extension() << "\n";
    }
    std::cout << "\n";
    if (m_removable != nullptr) {
        std::cout << "@" << m_removable->get_name() << ":";
        for (int i = 0; i < m_removable->items_count(); i++) {
            std::cout << i << "-" << m_removable->read(i)->get_name()<<m_removable->read(i)->get_extension() << "\n";
        }
        
    }
    std::cout << "\n";
}

int file_manager::find(std::string file_name, std::string device_name)
{
    if(m_internal->get_name() == device_name)
    {
        for (int i = 0; i < m_internal->items_count(); i++) {
            if(file_name == m_internal->read(i)->get_name())
                return i;

        }
            std::cout << "file not found! \n" ;
    }
    else if (m_removable->get_name() == device_name)
    {
        for (int i = 0; i < m_removable->items_count(); i++) {
            if(file_name == m_removable->read(i)->get_name())
                return i;
        }
        std::cout << "file not found! \n" ;
    }
    else
        std::cout << "device not found! \n";
    return -1;
}

void file_manager::remove(std::string file_name,std::string device_name)
{
    if(m_internal->get_name() == device_name)
    {
        int index = find(file_name, device_name);
        if(index != -1)
            m_internal->erase(find(file_name, device_name));
    }
    if(m_removable->get_name() == device_name)
    {
        int index = find(file_name, device_name);
        if(index != -1)
            m_removable->erase(find(file_name, device_name));
    }
}
