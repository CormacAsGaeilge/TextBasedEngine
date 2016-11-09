#include "InteractableCharacter.h"

InteractableCharacter::InteractableCharacter(unsigned int id, std::string name, std::string description, unsigned int health,
	std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft,
	DynamicItem equippedRight)
	: Character(id, name, description, health, itemPouch, wallet, state)
{
	setLeftEquip(equippedLeft);
	setRightEquip(equippedRight);
}

InteractableCharacter::InteractableCharacter()
{

}

InteractableCharacter::~InteractableCharacter()
{

}

