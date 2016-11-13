/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Weapon.h"
#include <iostream>
#include <string>
Weapon::Weapon(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, unsigned int attack, unsigned int defense, unsigned int speed)
	: DynamicItem(id,name,description,value,state,uses)
{
	setAttack(attack);
	setDefense(defense);
}

Weapon::Weapon()
{

}

Weapon::~Weapon()
{

}

void Weapon::setAttack(unsigned int attack)
{
	Weapon::attack = (attack > 0) ? attack : 20;
}

void Weapon::setDefense(unsigned int defense)
{
	Weapon::defense = (defense > 0) ? defense : 10;
}

void Weapon::setSpeed(unsigned int speed)
{
	Weapon::speed = (speed > 0) ? speed : 5;
}

void Weapon::print()
{
	DynamicItem::print();
	std::cout << "\nAttack\t" << Weapon::getAttack() << "\nDefense\t" << Weapon::getDefense() << std::endl;
}