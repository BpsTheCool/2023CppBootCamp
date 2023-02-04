//
//  file.hpp
//  os_file_manager_model
//
//  Created by alireza on 11/1/1401 AP.
//

#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <iostream>
#include <string>

class file
{
protected:
    std::string m_name;
    std::string m_extension;
    int m_size;
    //ptr to device as location
    int m_permission;
public:
    file();
    file(std::string name,std::string ext, int size, int permission);
//    file(file &to_copy);
    std::string get_name() {return m_name;};
    std::string get_extension() {return m_extension;};
    int get_size() {return m_size;};
    int get_permission() {return m_permission;};
    void get_info();
    void set_name(std::string name) {m_name = name;};
    
};

#endif /* file_hpp */
