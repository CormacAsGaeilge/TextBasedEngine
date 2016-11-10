#include "PlayerCharacter.h"
#include <iostream>
#include <string>


PlayerCharacter::PlayerCharacter(unsigned int id, std::string name, std::string description, unsigned int health,
	std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft,
	DynamicItem equippedRight)
	: Character(id, name, description, health, itemPouch, wallet, state, equippedLeft, equippedRight)
{
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::print()
{
	Character::print();
	
}