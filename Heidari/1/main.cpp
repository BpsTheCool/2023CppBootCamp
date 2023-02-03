#include <QCoreApplication>
#include "filemanager.h"
#include "fileclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager manager ;
    char choice;
    std::cout << "****************File Manager Program ***************"<< std::endl ;
    while(true)
    {
         system("clear");
        std::cout << "1)Exit" << std::endl;
        std::cout << "2)Add Hdd and File" << std::endl;
        int input;
        std::cin >> input;
        std::cin.get();
        switch (input) {
        case 1:
          return 0 ;
        case 2:
        {
             system("clear");
            FileClass file;
            file.setFileName("file1");
            file.setFileSize(128);
            manager.addInternalHDD();
            manager.addFileToHdd(file);
        }
            break;;
        }

    }

    return a.exec();
}
