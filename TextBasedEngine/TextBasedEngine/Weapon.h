#pragma once
#include "DynamicItem.h"

class Weapon : public DynamicItem
{
public:
	Weapon(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, unsigned int attack, unsigned int defense);
	Weapon();
	~Weapon();

	unsigned int getAttack() const { return attack; }
	unsigned int getDefense() const { return defense; }

	void setAttack(unsigned int attack);
	void setDefense(unsigned int defense);
	void print();
private:
	unsigned int attack;
	unsigned int defense;
};

