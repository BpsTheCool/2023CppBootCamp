#include <iostream>
#include "SharedPointer.h"


class Person {
	int age;
public:
	Person(int age)
		:
		age(age) {}

	int getAge() const {
		return age;
	}
};

int main() {
	
	//int
	SharedPointer<int> ptr(new int);
	*ptr = 10;

	{
		SharedPointer<int> ptr2 = ptr;
		std::cout << *ptr2 << std::endl;
		std::cout << ptr2.used() << std::endl;
		{
			SharedPointer<int> ptr3;
			ptr3 = ptr2;
			std::cout << *ptr3 << std::endl;
			std::cout << ptr3.used() << std::endl;
		}
		std::cout << ptr2.used() << std::endl;
	}
	std::cout << *ptr << std::endl;
	std::cout << ptr.used() << std::endl;

	//Person
	SharedPointer<Person> amir(new Person(25));
	std::cout << amir->getAge() << std::endl;
	{
		SharedPointer<Person> twin = amir;
		std::cout << twin->getAge() << std::endl;
		std::cout << twin.used() << std::endl;

	}
	std::cout << amir.used() << std::endl;

	system("pause>nul");
	return 0;
}