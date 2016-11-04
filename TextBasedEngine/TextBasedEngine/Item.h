#pragma once
#include "Object.h"
class Item : public Object
{
public:
	Item(unsigned int id, std::string name, std::string description, unsigned int value);
	Item();
	~Item();

	unsigned int getValue() const { return value; }

	void setValue(unsigned int value);
	void print();
private:
	unsigned int value;
};

