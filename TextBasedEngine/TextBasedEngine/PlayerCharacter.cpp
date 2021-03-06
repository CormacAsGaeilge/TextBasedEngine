/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "PlayerCharacter.h"
#include <iostream>
#include <string>

PlayerCharacter::PlayerCharacter(unsigned int id, std::string name, std::string description, unsigned int health,
	std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft,
	DynamicItem* equippedRight)
	: Character(id, name, description, health, itemPouch, wallet, state, equippedLeft, equippedRight)
{

}

PlayerCharacter::PlayerCharacter(Character character)
{

}
PlayerCharacter::~PlayerCharacter()
{

}

void PlayerCharacter::print()
{
	Character::print();
}

void PlayerCharacter::interaction(std::string action, DynamicItem item)
{
	if (action == "Search")
		search();
	else if (action == "Use")
		use(item);
	else if (action == "Interact")
		interact(item);
	else if (action == "LookAt")
		lookAt(item);
}



void PlayerCharacter::search()
{
	std::cout << "You search the room." << std::endl;
}

void PlayerCharacter::use(DynamicItem item)
{
	std::cout << "You used the " << item.getName() << std::endl;
}

void PlayerCharacter::interact(DynamicItem item)
{
	std::cout << "You interacted with the " << item.getName() << std::endl;
}

void PlayerCharacter::lookAt(DynamicItem item)
{
	std::cout << "You Look at the " << item.getName() << std::endl;
	std::cout << item.getDescription() << std::endl;
}
