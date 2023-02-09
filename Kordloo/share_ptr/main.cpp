#include <QCoreApplication>
#include "sh_ptr.h" //for adding shrareptr
#include <iostream>


// creating shared pointer
//shared_ptr<int> ptr1 = make_shared<int>();
//*ptr1 = "Educative";
// Only one pointer points to string object
//cout << "ptr1 count = " << ptr1.use_count() << endl;
// Now second pointer points to the same int object
//shared_ptr<string> ptr2(ptr1);
//cout << "ptr2 is pointing to the same object as ptr1. Now counts are:" << endl;
// Shows the count after two pointer points to the same object.
//cout << "ptr2 count = " << ptr2.use_count() << endl;
//cout << "ptr1 count = " << ptr1.use_count() << endl;
int main()
{
    int ptr1{};
    int ptr2{};
    sh_ptr smartPointer1(new int (ptr1));

    std::cerr<<"ptr 1 count:";
    std::cerr<<smartPointer1.getShareptr()<<"\n";


    sh_ptr smartPointer2(smartPointer1);
    std::cerr<<"ptr 1 count:";
    std::cerr<<smartPointer2.getShareptr()<<"\n";

    sh_ptr smartPointer(new int (ptr2));
    std::cerr<<"ptr 2 count:";
    std::cerr<<smartPointer.getShareptr()<<"\n";
    {
        sh_ptr smartpointer5(smartPointer);
        std::cerr<<"ptr  count:";
        std::cerr<<smartpointer5.getShareptr()<<"\n";


    }
    std::cerr<<"ptr final count:";
    std::cerr<<smartPointer.getShareptr()<<"\n";
//    std::cerr<<smartPointer1.getShareptr()<<"\n";



}

