#pragma once
#include "DynamicItem.h"

class Weapon : public DynamicItem
{
public:
	Weapon(unsigned int attack, unsigned int defense);
	Weapon();
	~Weapon();

	unsigned int getAttack() const { return attack; }
	unsigned int getDefense() const { return defense; }

	void setAttack(unsigned int attack);
	void setDefense(unsigned int defense);

private:
	unsigned int attack;
	unsigned int defense;
};

