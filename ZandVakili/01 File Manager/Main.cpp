#include <iostream>
#include "HDD.h"
#include "CD.h"
#include <conio.h>
#include <vector>

//    (_getch() - '0')    :    char number to int number

int main()
{
	std::vector <HDD> HDDs;
	std::vector <CD> CDs;
	Device* ptr;

	while (true)
	{
	menu:

		system("cls");
		std::cout << "\n List of Devices and Discs :" << std::endl;
		std::cout << "\ta . List of HDDs :" << std::endl;
		for (int i = 0; i < HDDs.size(); i++)
		{
			std::cout << "\t\t" << i + 1 << ". " << HDDs.at(i).getDeviceName() << '\n';
		}
		std::cout << " \tb . List of CDs :" << std::endl;
		for (int i = 0; i < CDs.size(); i++)
		{
			std::cout << "\t\t" << i + 1 << ". " << CDs.at(i).getDeviceName() << '\n';
		}
		std::cout << "\n - PRESS the Dedicated Character of Drives [a/b/...] To Select between them. " << std::endl;
		std::cout << "\n - PRESS [n] To Connect/Insert a Device/Disc. " << std::endl;
		std::cout << "\n - PRESS [e] To Disconnect/Eject a Device/Disc. " << std::endl;

		switch (_getch())
		{
		case 'a':
		case 'A':
			if (HDDs.empty()) continue;
			std::cout << std::endl;
			std::cout << "Selencting a HDD..." << std::endl;
			std::cout << "Press its dedicated number [1/2/...] : ";
			ptr = &HDDs.at((_getch() - '0') - 1);
			goto drive;
		case 'b':
		case 'B':
			if (CDs.empty()) continue;
			std::cout << std::endl;
			std::cout << "Selencting a CD : ";
			std::cout << "Press its dedicated number [1/2/...] : ";
			ptr = &CDs.at((_getch() - '0') - 1);
			goto drive;
		case 'n':		
		case 'N':		
			goto newDevice;
		case 'e':
		case 'E':
			goto ejectDevice;
		default:
			continue;
		}
	}
	//-----Accessing-Drive-----
	while (true)
	{
	drive:
		system("cls");
		std::cout << "Drive Name : " << ptr->getDeviceName() << std::endl;
		std::cout << "Drive Total Space : " << ptr->getDeviceStorage() << "Mb" << std::endl;
		ptr->printFilesList();
		std::cout << " 1. add file." << std::endl;
		std::cout << " 2. delete a file." << std::endl;
		std::cout << " 3. clear drive." << std::endl;
		std::cout << " 4. BACK" << std::endl;
		switch (_getch())
		{
		case '1':
		{
			if (ptr->getDeviceStorage() < 4) {
				std::cout << "NOT enough space available! press any key to continue." << std::endl;
				_getch();
				continue;
			}
			std::string name;
			std::cout << "Please Enter Name of the File : ";
			std::cin >> name;
			ptr->newFile(name);
			std::cout << "File successfully added! press any key to continue.";
			_getch();
			continue;
		}
		case '2':
		{
			std::cout << "Please enter index of the file you want to delete : ";
			int index;
			std::cin >> index;
			ptr->deleteFile(index - 1);
			std::cout << "File successfully deleted! press any key to continue.";
			_getch();
			continue;
		}
		case '3':
			ptr->formatDevice();
			_getch();
			continue;
		case '4':
			goto menu;
		default:
			continue;
		}
	}
	//----Ejecting-a-Drive-----
	while (true)
	{
	ejectDevice:
		std::cout << "Please select device type [a/b/...] : " << std::endl;
		switch (_getch())
		{
		case 'a':
		case 'A':
			std::cout << "Please select device decicated number [1/2/...] : " << std::endl;
			HDDs.erase(HDDs.begin() + (_getch() - '0') - 1);
			std::cout << "HDD has been successfully disconnected! press any key to continue.";
			_getch();
			goto menu;
		case 'b':
		case 'B':
			std::cout << "Please select device decicated number [1/2/...] : " << std::endl;
			CDs.erase(CDs.begin() + (_getch() - '0') - 1);
			std::cout << "CD has been successfully ejected! press any key to continue.";
			_getch();
			goto menu;
		default:
			break;
		}
	}
	//-----Adding-a-new-Drive
	while (true)
	{
	newDevice:

		system("cls");

		std::cout << " Adding a new drive..." << std::endl;
		std::cout << " Please select : " << std::endl;
		std::cout << " 1. HDD" << std::endl;
		std::cout << " 2. CD" << std::endl;
		switch (_getch())
		{
		case '1':
		{
			std::string name;
			std::cout << "Enter HDD Name : ";
			std::cin >> name;
			HDD temp(name);
			HDDs.push_back(temp);
			std::cout << "HDD has been connected! press any key to continue.";
			_getch();
			goto menu;
		}
		case '2':
		{
			std::string name;
			std::cout << "Enter CD Name : ";
			std::cin >> name;
			CD temp(name);
			CDs.push_back(temp);
			std::cout << "CD has been inserted! press any key to continue.";
			_getch();
			goto menu;
		}
		default:
			continue;
		}
	}

	system("pause>nul");
	return 0;
}