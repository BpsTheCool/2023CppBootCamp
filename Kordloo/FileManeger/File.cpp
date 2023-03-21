#include "File.h"

std::string File::name() const
{
    return m_name;
}

int File::size() const
{
    return m_size;
}

File::File(std::string name, int size)
    :m_name(name),
      m_size(size)
{

}
