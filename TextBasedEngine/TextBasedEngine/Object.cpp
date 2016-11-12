/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Object.h"
#include <iostream>
#include <string>

Object::Object(unsigned int id, std::string name, std::string description)
{
	setId(id);
	setName(name);
	setDescription(description);
}

Object::Object()
{

}

Object::~Object()
{

}

void Object::setId(unsigned int id)
{
	Object::id = (id > 0) ? id : 1;
}

void Object::setName(std::string name)
{
	Object::name = (name.length() > 3) ? name : "default name";
}

void Object::setDescription(std::string description)
{
	Object::description = (description.length() > 8) ? description : "default description";
}

void Object::print() 
{
	std::cout << "Name\t" << Object::getName() << "\nDes\t" << Object::getDescription();
}
