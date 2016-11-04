#include "Item.h"
#include <iostream>
#include <string>

Item::Item(unsigned int id, std::string name, std::string description, unsigned int value) : Object(id,name,description)
{
	setValue(value);
}

Item::Item()
{

}

Item::~Item()
{

}

void Item::setValue(unsigned int value)
{
	Item::value = (value > 0) ? value : 1;
}

void Item::print()
{
	Object::print();
	std::cout << "\nItem Value\t" << Item::getValue();
}