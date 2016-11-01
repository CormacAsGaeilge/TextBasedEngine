#pragma once
#include "Object.h"
class Item : public Object
{
public:
	Item(unsigned int value);
	Item();
	~Item();

	unsigned int getValue() const { return value; }

	void setValue(unsigned int value);

private:
	unsigned int value;
};

