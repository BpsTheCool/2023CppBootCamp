#ifndef FILE_H
#define FILE_H
#include<string>

class File
{
     std::string m_name;
     int m_size;
public:
     File()=default;
     File(std::string name,int size);
     std::string name() const;
     int size() const;
};

#endif // FILE_H
