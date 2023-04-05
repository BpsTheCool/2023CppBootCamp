#include "smartpointer.h"
#include <iostream>
#include <QDebug>

int main()
{
    shared_pointer a1 = new int(4);
    shared_pointer a2 = std::move(a1);
    shared_pointer a3 = a2;
{
    shared_pointer a4 = a3;
}
//    shared_pointer a5 = a4;   error:a4 is destructed

    *a2=7;
    qInfo()<< "a2: " <<*a2 ;
    qInfo()<< "a3: " <<*a3 ;
    qInfo()<< "count pointers (a): " <<a3.countPointers();


    shared_pointer b1;
//    b1 = new int(512);
    b1.reset(new int (512));
    shared_pointer b2;
    b2=b1;
    shared_pointer b3;
    b3=std::move(b1);
    shared_pointer b4;
    b4=b3;

    qInfo()<< "b2: " <<*b2;
    qInfo()<< "b3: " <<*b3;
    qInfo()<< "b4: " <<*b4;
    qInfo()<< "count pointers (b): " <<b2.countPointers();
    qInfo()<< "count pointers (a): " <<a3.countPointers();
}
