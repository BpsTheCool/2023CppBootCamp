#include "ReferenceCounter.h"

void ReferenceCounter::increase() {
	counter++;
}

void ReferenceCounter::decrease() {
	counter--;
}

int ReferenceCounter::getCount() const{
	return counter;
}