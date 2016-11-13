/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Consumable.h"
#include <iostream>
#include <string>


Consumable::Consumable(unsigned int id, std::string name, std::string description, unsigned int value, 
	bool state, unsigned int uses, ConsumableType consumableType, int effectValue)
	: DynamicItem(id, name, description, value, state, uses)
{
	setConsumableType(consumableType);
	setEffectValue(effectValue);
}


Consumable::~Consumable()
{

}

void Consumable::setConsumableType(ConsumableType consumableType)
{
	Consumable::consumableType = consumableType;
}

void Consumable::setEffectValue(int effectValue) 
{
	Consumable::effectValue = (effectValue > 0) ? effectValue : 10;
}

void Consumable::print()
{
	DynamicItem::print();
	std::cout << "ConsumableType\t" << Consumable::getConsumableType() << "\nEffect Value\t" << Consumable::getEffectValue()<<std::endl;
}
void Consumable::useItem()
{
	DynamicItem::useItem();
	if(Consumable::consumableType == healthPotion)
		std::cout << "The " << Consumable::getName() << " is consumed and your health increases by " << Consumable::getEffectValue() << "." << std::endl;
	else
	{
		std::cout << "The " << Consumable::getName() << " is consumed and your health decreases by " << Consumable::getEffectValue() << "." << std::endl;
	}
}