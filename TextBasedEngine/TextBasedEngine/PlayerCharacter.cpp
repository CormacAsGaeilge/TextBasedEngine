#include "PlayerCharacter.h"
#include <iostream>
#include <string>


PlayerCharacter::PlayerCharacter(unsigned int id, std::string name, std::string description, unsigned int health,
	std::vector<std::unique_ptr<DynamicItem>> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft,
	DynamicItem equippedRight)
	: InteractableCharacter(id, name, description, health, itemPouch, wallet, state, equippedLeft, equippedRight)
{
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::print()
{
	Character::print();
	std::cout << "\nLeft Hand\t";
	PlayerCharacter::getLeftEquip().print();
	std::cout << "\nRight Hand\t";
	PlayerCharacter::getRightEquip().print();
	std::cout<< std::endl;
}