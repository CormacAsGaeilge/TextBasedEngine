#include "Character.h"
#include <iostream>
#include <memory>
#include <string>

Character::Character(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<std::unique_ptr<DynamicItem>> itemPouch, unsigned int wallet, bool state)
	: Object(id, name, description)
{
	setHealth(health);
	setItemPouch(itemPouch);
	setWallet(wallet);
	setState(state);
}

Character::Character() : Object()
{

}


Character::~Character()
{

}

void Character::setHealth(unsigned int health)
{
	Character::health = (health > 0) ? health : 30;
}

void Character::setItemPouch(std::vector<std::unique_ptr<DynamicItem>> itemPouch)
{
	Character::itemPouch = itemPouch;
}

void Character::setWallet(unsigned int wallet)
{
	Character::wallet = (wallet > 0) ? wallet : 10;
}

void Character::setState(bool state)
{
	Character::state = (state != false) ? state : true;
}

void Character::print()
{
	Object::print();
	std::cout << "\nHealth\t" << Character::getHealth() << "\nWallet\t" << Character::getWallet() << "\nItemPouch\t";
	Character::printItemPouch();

}
void Character::printItemPouch()
{
	std::cout << "*****ITEM POUCH*****" << std::endl;
	if (!Character::itemPouch.empty())
	{
		for (int i=0; i < (int)itemPouch.size(); i++)
		{
			itemPouch.at(i)->print();
		}
	}
	else
	{
		std::cout << "Empty Pouch" << std::endl;
	}
	std::cout << "********************" << std::endl;
}