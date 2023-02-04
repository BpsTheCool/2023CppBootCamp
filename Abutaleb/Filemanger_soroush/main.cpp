#include <iostream>
#include<vector>
#include "Filemanger.h"
#include "Device.h"
#include "Drive.h"
#include "File.h"

using namespace std;

enum inputs {
    hdd=0,
    ssd=2,
    flashmemory=4
};

int main()
{
    vector<Device*> d;
    vector<Drive*> dr;

    cout << "you don't have any Device in this system , "<<endl;
    cout << "please insert one of them((0)ssd/(1)hdd)"<< endl;
    int choicedevice;
    cin >> choicedevice;
    inputs i;

    switch(choicedevice)
    {
        case 0 :if(choicedevice==0){
            d.push_back(new Ssd("MainDisk" , 5000));
            d.at(0)->insert();break;

        }
        case 1 :if(choicedevice==1){
            d.push_back(new Hdd("Main Disk" , 5000));
            d.at(0)->insert();break;
            }
    }

    Filemanger f(d , dr);
    while(true){
        cout<<endl<<"//----------------------------"<<endl;
        cout<<endl<<"//----------------------------"<<endl;
        f.print();
        cout<<endl<<"//----------------------------"<<endl;
        cout<<endl<<"//----------------------------"<<endl;

        cout << "1-insertDevice" << "  ";
        cout << "2-ejectDevice" << "  ";
        cout << "3-addDrive" << "  ";
        cout << "4-removeDrive" << "  ";
        cout << "5-changeDirctory" << "  ";
        cout << endl<< "type your command: "<<endl;

        int command;
        cin >> command;

        if(command==3)
        {
            cout << "choose your device: ";
            string choose;
            cin>>choose;
            for(auto it=d.begin() ; it != d.end() ; it++){
//                cout<<(*it)->getnamedevice();
//                cout<<choose;

                if((*it)->getnamedevice()==choose){
                    if((*it)->Driveable())
                    {
                        cout << "Device is exist , please type your name Drive:";
                        string namedrive;
                        cin>>namedrive;
                        cout << "please type size your Drive:";
                        double sizedrive;
                        cin>>sizedrive;
                        auto newdrive=f.adddrive(new Drive(*it , namedrive , sizedrive) , *it);

                        if((*it)->getsizedevice()>newdrive->sizedrive())
                        {
                            cout<<"test";
                        auto newsize=((*it)->getsizedevice()) - (newdrive->sizedrive());
                        (*it)->setsizedevice(newsize);
                        break;
                        }
                        else
                        {

                            cout<<"you don't have enough volume, please delete some files";
                            //delete newdrive;
                        }
                    }
                    else
                        cout<<"you can not make drive on type of this Device"<<endl;
                    }
                else
                {
                    cout<<"there isn't any Device with this name "<<endl;
                    cout<<"fist add new device"<<endl;
                }
            }
        }


    }





    return 0;
}
