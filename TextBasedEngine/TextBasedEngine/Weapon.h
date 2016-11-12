/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "DynamicItem.h"

class Weapon : public DynamicItem
{
public:
	Weapon(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, unsigned int attack, unsigned int defense, unsigned int speed);
	Weapon();
	~Weapon();

	unsigned int getAttack() const { return attack; }
	unsigned int getDefense() const { return defense; }
	unsigned int getSpeed() const { return speed; }

	void setAttack(unsigned int attack);
	void setDefense(unsigned int defense);
	void setSpeed(unsigned int speed);
	void print() override;
private:
	unsigned int attack,defense,speed;
};

