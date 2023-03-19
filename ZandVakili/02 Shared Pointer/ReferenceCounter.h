#pragma once

class ReferenceCounter {

	int counter;

public:

	ReferenceCounter()
		:
		counter(0) 
	{}

	void increase();
	void decrease();
	int getCount() const;
};