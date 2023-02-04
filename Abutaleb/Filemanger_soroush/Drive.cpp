#include "Drive.h"
#include "Device.h"
#include "File.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

Drive::Drive(Device* d, string name, double size)
            :forcedevice(d) , m_namedrive(name) , m_sizedrive(size)
{

}

string Drive::namedrive()
{
    return m_namedrive;
}

double Drive::sizedrive()
{
    return m_sizedrive;
}
