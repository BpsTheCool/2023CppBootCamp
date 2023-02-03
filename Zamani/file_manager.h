//
//  file_manager.h
//  os_file_manager_model
//
//  Created by alireza on 11/2/1401 AP.
//

#ifndef file_manager_h
#define file_manager_h

#include <iostream>
#include "device.h"
#include "file.h"

class file_manager
{
    device *m_internal;
    device *m_removable = nullptr;
public:
    file_manager();
    void create_file();
    void show_capacity();
    device* get_device(){return m_internal;};
    void mount(device *flash_drive);
    void save_to_internal(file &f);
    void save_to_external(file &f);
    void search(std::string filename);
    void show_all_files();
    int find(std::string file_name,std::string device_name="01");
    void remove(std::string file_name,std::string device_name="01");
};

#endif /* file_manager_h */
