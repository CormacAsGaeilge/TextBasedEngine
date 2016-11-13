/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

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
	virtual void print();
private:
	unsigned int value;
};

