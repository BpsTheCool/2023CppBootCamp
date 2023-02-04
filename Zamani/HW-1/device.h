#ifndef DEVICE_H
#define DEVICE_H

#include "file.h"
#include <iostream>
#include <string>
#include <vector>

class device
{
protected:
    int m_capacity = 0;
    std::string m_name;
    std::vector<file> storage;
    std::string m_type;
public:
    device(int size, std::string name, std::string type);
    // ~device() {};
    virtual file *read(int file_index) = 0;
    virtual void write(file &f) = 0;
    virtual int get_size()=0;
    virtual std::string get_name()=0;
    virtual std::string get_type()=0;
    virtual int items_count()=0;
    virtual void erase(int file_index)=0;

};

class disk_drive : public device
{
private:
    /* data */
public:
    disk_drive(int size, std::string name, std::string type);
    // ~removable_device();
    file *read(int file_index) override;
    void write(file &f) override;
    int get_size() override {return m_capacity;};
    std::string get_name() override {return m_name;}
    std::string get_type() override {return m_type;}
    int items_count() override {return storage.size();}
    void erase(int file_index) override;
};

// class disk_drive : public device
// {
// private:

// public:
//     disk_drive(int size);
//     ~disk_drive();
//     // void mount();
//     // void eject();
//     void read();
//     void write();

// };















#endif /* device_h */
