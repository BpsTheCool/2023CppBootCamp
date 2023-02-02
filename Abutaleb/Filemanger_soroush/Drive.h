#ifndef DRIVE_H
#define DRIVE_H

#include "Drive.h"
#include "Device.h"
#include<iostream>
#include<vector>
#include<string>

class Device;

using namespace std;

class Drive
{
    string m_namedrive;
    double m_sizedrive;
    Device* forcedevice;
public:
    Drive(Device* d , string name , double size);
    string namedrive();
    double  sizedrive();
};

#endif // DRIVE_H
