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

Character::setHealth(health)
{
	Character::health = (health > 0) ? health : 30;
}

Character::setItemPouch(itemPouch)
{
	Character::itemPouch = (itemPouch > 0) ? itemPouch : 1;
}

Character::setWallet(wallet)
{
	Character::wallet = (wallet > 0) ? wallet : 10;
}

Character::setState(state)
{
	Character::state = (state != false) ? state : true;
}