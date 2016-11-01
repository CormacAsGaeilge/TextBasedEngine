#include "Character.h"

Character::Character(unsigned int health, unsigned int itemPouch, unsigned int wallet, bool state)
{
	setHealth(health);
	setItemPouch(itemPouch);
	setWallet(wallet);
	setState(state);
}

Character::Character()
{

}


Character::~Character()
{

}

void Character::setHealth(unsigned int health)
{
	Character::health = (health > 0) ? health : 30;
}

void Character::setItemPouch(unsigned int itemPouch)
{
	Character::itemPouch = (itemPouch > 0) ? itemPouch : 1;
}

void Character::setWallet(unsigned int wallet)
{
	Character::wallet = (wallet > 0) ? wallet : 10;
}

void Character::setState(bool state)
{
	Character::state = (state != false) ? state : true;
}