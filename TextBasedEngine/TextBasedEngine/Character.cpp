/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Character.h"
#include <iostream>
#include <memory>
#include <string>

Character::Character(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight)
	: Object(id, name, description)
{
	setHealth(health);
	setItemPouch(itemPouch);
	setWallet(wallet);
	setState(state);
	setLeftEquip(equippedLeft);
	setRightEquip(equippedRight);
}

Character::Character() : Object()
{
}


Character::~Character()
{
	for (DynamicItem* ptr : Character::itemPouch)
		delete ptr;
	itemPouch.clear();
}

void Character::setHealth(unsigned int health)
{
	Character::health = (health > 0) ? health : 30;
}

void Character::setItemPouch(std::vector<DynamicItem*> itemPouch)
{
	Character::itemPouch = itemPouch;
}

void Character::setWallet(unsigned int wallet)
{
	Character::wallet = (wallet > 0) ? wallet : 10;
}

void Character::setState(bool state)
{
	Character::state = state;
}

void Character::print()
{
	Object::print();
	std::cout << "\nHealth\t" << Character::getHealth() << "\nWallet\t" << Character::getWallet() << "\nItemPouch\t";
	Character::printItemPouch();

}

void Character::printItemPouch()
{
	std::cout << "\n*****ITEM POUCH*****" << std::endl;
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
	std::cout << "\nLeft Hand\t";
	Character::getLeftEquip()->print();
	std::cout << "\nRight Hand\t";
	Character::getRightEquip()->print();
	std::cout << std::endl;
}

void Character::pickUp(DynamicItem* item)
{
	std::cout << "You picked up the " << item->getName() << std::endl;
	Character::itemPouch.push_back(item);
}