/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Key.h"
#include <iostream>

Key::Key(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, unsigned int lockId)
	: DynamicItem(id,name,description,value,state,uses)
{
	setLockId(lockId);
}

Key::Key()
{

}

Key::~Key()
{

}

void Key::setLockId(unsigned int lockId)
{
	Key::lockId = (lockId > 0) ? lockId : 1;
}

void Key::print()
{
	DynamicItem::print();
	std::cout << "\nLockId\t" << Key::getLockId() << std::endl;
}