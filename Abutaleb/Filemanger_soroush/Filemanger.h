#ifndef FILEMANGER_H
#define FILEMANGER_H

#include "Device.h"
#include "Drive.h"
#include"Device.h"
#include "File.h"
#include<iostream>
#include<vector>

using namespace std;


class Filemanger
{
    vector<Device*> &m_device;
    vector<Drive*> m_drive;
    //Device m_currentdevice;
public:
    Filemanger(vector<Device*> &device, vector<Drive*> &derive);

    void print();
    void CreatFile();
    Drive* adddrive(Drive* dr, Device *d);
    void insertdevice(Plugable *p);
};

#endif // FILEMANGER_H
