/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "DynamicItem.h"
#include "ConsumableType.h"
class Consumable :
	public DynamicItem
{
public:
	Consumable(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, ConsumableType consumableType, int effectValue);
	~Consumable();
	ConsumableType getConsumableType() { return consumableType; }
	int getEffectValue() { return effectValue; }

	void setConsumableType(ConsumableType consumableType);
	void setEffectValue(int effectValue);
	void print() override;
private:
	ConsumableType consumableType;
	int effectValue;
};

