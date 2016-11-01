#include "Weapon.h"

Weapon::Weapon(unsigned int attack, unsigned int defense)
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
