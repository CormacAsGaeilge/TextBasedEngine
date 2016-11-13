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
	//Object::id = (id > -1) ? id : 0;
	Object::id = id;
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
