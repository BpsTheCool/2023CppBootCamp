#pragma once
#include "ReferenceCounter.h"

template<typename T>
class SharedPointer {

	T* pointer;
	ReferenceCounter* referenceCounter;

public:

	SharedPointer()
		:
		pointer(nullptr),
		referenceCounter(new ReferenceCounter()) {
		referenceCounter->increase();
	}

	SharedPointer(T* pointer)
		:
		pointer(pointer),
		referenceCounter(new ReferenceCounter()) {
		referenceCounter->increase();
	}

	SharedPointer(const SharedPointer<T>& newPointer)
		:
		pointer(newPointer.pointer),
		referenceCounter(newPointer.referenceCounter) {
		referenceCounter->increase();
	}

	~SharedPointer() {
		referenceCounter->decrease();
		if (referenceCounter->getCount() == 0) {

			if (pointer) {
				delete pointer;
				pointer = nullptr;
			}

			if (referenceCounter) {
				delete referenceCounter;
				referenceCounter = nullptr;
			}
		}
	}

	T& operator*() {
		return *(pointer);
	}

	T* operator->() {
		return pointer;
	}

	SharedPointer<T>& operator=(const SharedPointer<T>& newPointer) {

		if (this != &newPointer) {
			referenceCounter->decrease();
			if (referenceCounter->getCount() == 0) {

				if (pointer) {
					delete pointer;
					pointer = 0;
				}

				if (referenceCounter) {
					delete referenceCounter;
					referenceCounter = 0;
				}
			}

			pointer = newPointer.pointer;
			referenceCounter = newPointer.referenceCounter;
			referenceCounter->increase();
		}
		return *this;
	}

	int used() {
		return referenceCounter->getCount();
	}
};