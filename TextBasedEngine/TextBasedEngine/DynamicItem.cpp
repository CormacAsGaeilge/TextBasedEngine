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
	DynamicItem::state = (state != false) ? state : true;
}

void DynamicItem::setUses(unsigned int uses)
{
	DynamicItem::uses = (uses > -1) ? uses : 0;
}
void DynamicItem::print()
{
	Item::print();
	std::cout << "\nUses\t" << DynamicItem::getUses();
}