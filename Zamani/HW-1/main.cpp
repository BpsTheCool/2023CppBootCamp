//
//  main.cpp
//  os_file_manager_model
//
//  Created by alireza on 11/1/1401 AP.
//

#include <iostream>
#include <string>
#include "device.h"
#include "file.h"
#include "file_manager.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    file_manager manager;
    manager.show_capacity();
    manager.create_file();
    disk_drive flash(500,"my_flash","removable");
    manager.mount(&flash);
    manager.search("alireza");
    manager.show_all_files();
    manager.remove("alireza");
    manager.show_all_files();
    

    return 0;
}
