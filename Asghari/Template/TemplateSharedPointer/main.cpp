#include <iostream>
#include "TemplateSharedPointer.h"

//using namespace std;

int main()
{




    // Create a int shared pointe
    MySharedPtr<int> sharedInt(new int(25));
    std::cout << "counter for int: ";
    sharedInt.getCounter();

    // Create a double shared pointer
    MySharedPtr<double> sharedDouble(new double(25.5555));
    std::cout << "counter for double: ";
    sharedDouble.getCounter();

    // value of the pointers
    std::cout << "Value of shared pointer to integer: " << *sharedInt << std::endl;
    std::cout << "Value of shared pointer to double: " << *sharedDouble << std::endl;

    // Copy Constructor
    MySharedPtr<int> sharedInt2 = sharedInt;
    std::cout << "counter for int: ";
    sharedInt.getCounter();

    // change the value
    *sharedInt = 50;
    std::cout << "Value of int: " << *sharedInt << std::endl;
    std::cout << "Value of int 2: " << *sharedInt2 << std::endl;

    // new value
    sharedInt = MySharedPtr<int>(new int(500));
    std::cout << "counter for int: ";
    sharedInt.getCounter();


    return 0;
}
