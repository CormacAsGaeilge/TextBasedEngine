/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "DynamicItem.h"
#include <iostream>
#include <string>

DynamicItem::DynamicItem(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses) : Item(id,name,description,value)
{
	setState(state);
	setUses(uses);
}

DynamicItem::DynamicItem()
{

}

DynamicItem::~DynamicItem()
{

}

void DynamicItem::setState(bool state)
{
	DynamicItem::state = state;
}

void DynamicItem::setUses(unsigned int uses)
{
	DynamicItem::uses = (uses > 0) ? uses : 0;
}
void DynamicItem::print()
{
	Item::print();
	std::cout << "\nUses\t" << DynamicItem::getUses() << std::endl << std::endl;
}