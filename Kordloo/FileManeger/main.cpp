#include <iostream>
#include <stdlib.h>
#include <map>
#include "Filemaneger.h"
#include "Divice.h"
#include "Hdd.h"
#include "Cd.h"
#include "ExternalHdd.h"
#include "FelashMemory.h"
#include "File.h"


enum class Comands
{

    addDivice,
    removeDivice,
    openDivice,
    exit
};

std::string setCommand()
{
    std::cerr<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
    std::cerr<<"             pleas insert your command:\n";
    std::cerr<<" help ==> addDivice   removeDivice   openDivice   exit\n";
    std::cerr<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
        std::string insert_command;
        std::cin >> insert_command;
        return insert_command;

}

Comands map_of_commands(std::string x)
{
    std::map<std::string,Comands> Memap
   {
    std::make_pair("addDivice",Comands::addDivice),
    std::make_pair("removeDivice",Comands::removeDivice),
    std::make_pair("openDivice",Comands::openDivice),
    std::make_pair("exit",Comands::exit)
   };


            for (auto &item : Memap)
            {
                if(x==item.first)
                {
                        return item.second;
                }
            }
}

int main()
{


FileManeger f;
Divice divice;



    bool key=true;
    while (key)
    {
        std::string a,b,c,d;
        a="hhd";
        b="felash";
        c="external";
        d="cd";
        label:
        system("cls");
        f.showdivices();
        Comands maincommand=map_of_commands(setCommand());

        switch(maincommand)
        {
            case Comands::addDivice :
            {
            addDivice:
            std::cerr<<"you can add this divices:"<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
            std::string divName;
            std::cin>> divName;
                if (divName=="hhd"){

                    f.setName(std::make_shared<Hdd>(divName));
                    a="";
                }
                else if(divName=="felash"){

                    f.setName(std::make_shared<FelashMemory>(divName));
                    b="";
                }
                else if(divName=="external"){

                    f.setName(std::make_shared<ExternalHdd>(divName));

                    c="";
                }
                else if(divName=="cd"){

                    f.setName(std::make_shared<Cd>(divName));

                    d="";
                }

                else {
                    std::cerr<<"\t <error> \n";
                    std::cerr<<"\t do you want to continue?(y/n)   ";
                    std::cin>> divName;
                     if (divName=="y"){
                         goto addDivice;
                     }
                     else {
                         key=false;
                         break;
                     }

                }
                goto label;
            }
            case Comands::removeDivice:
            {
            std::cerr<<"you can remove this divices:"<<"\t"<<"hhd"<<"\t"<<"felash"<<"\t"<<"external"<<"\t"<<"cd"<<"\n";
            std::string divName;
            std::cin>> divName;
            f.removedivice(divName);
            goto label;

            }
            case Comands::openDivice:
            {
            openDivice:
            std::cerr<<"\tyou want to open wich divices ?\t"<<"hhd"<<"\t"<<"felash"<<"\t"<<"external"<<"\t"<<"cd"<<"\n";
            std::string divName;
            std::cin>> divName;
            system("cls");
            if (divName=="hhd"){
                hhd:
                divice.showfiles();
                divice.uifile();
                std::string nn;
                std::cin>>nn;
                        if (nn=="addFile"){
                            std::cerr<<"\tpleas insert name and size of youe file\n";
                            std::string name;
                            int size;
                            std::cin>>name>>size;
                            divice.setFile(std::make_shared<Hdd>(name,size));
                            goto hhd;


                        }
                        else if(nn=="renameFile"){


                        }
                        else if(nn=="deletFile"){


                        }
                        else if(nn=="goBack"){
                              goto label;
                        }


            }
            else if(divName=="felash"){
                divice.showfiles();
                divice.uifile();
                std::string nn;
                std::cin>>nn;
                 if (nn=="addFile"){
                     std::cerr<<"\tpleas insert name and size of youe file\n";
                     std::string name;
                     int size;
                     std::cin>>name>>size;
                     divice.setFile(std::make_shared<Hdd>(name,size));

                 }
                 else if(nn=="renameFile"){


                 }
                 else if(nn=="deletFile"){


                 }
                 else if(nn=="goBack"){
                       goto label;
                 }

            }
            else if(divName=="external"){
                divice.showfiles();
                divice.uifile();
                std::string nn;
                std::cin>>nn;
                 if (nn=="addFile"){
                     std::cerr<<"\tpleas insert name and size of youe file\n";
                     std::string name;
                     int size;
                     std::cin>>name>>size;
                     divice.setFile(std::make_shared<Hdd>(name,size));


                 }
                 else if(nn=="renameFile"){


                 }
                 else if(nn=="deletFile"){


                 }
                 else if(nn=="goBack"){
                       goto label;
                 }

            }
            else if(divName=="cd"){
                divice.showfiles();
                divice.uifile();
                std::string nn;
                std::cin>>nn;
                  if (nn=="addFile"){
                      std::cerr<<"\tpleas insert name and size of youe file\n";
                      std::string name;
                      int size;
                      std::cin>>name>>size;
                      divice.setFile(std::make_shared<Hdd>(name,size));


                  }
                  else if(nn=="renameFile"){


                  }
                  else if(nn=="deletFile"){


                  }
                  else if(nn=="goBack"){
                        goto label;
                  }
            }

            else {
                std::cerr<<"\t <error> \n";
                std::cerr<<"\t do you want to continue?(y/n)   ";
                std::cin>> divName;
                     if (divName=="y"){
                         goto openDivice;
                     }
                     else {
                         key=false;
                         break;
                    }

                 }
            }
            case Comands::exit :
            {
              key=false;
              break;
        }
            break;
        }
    }


std::cerr<<"\t\tapp closed\n";


    return 0;
}
