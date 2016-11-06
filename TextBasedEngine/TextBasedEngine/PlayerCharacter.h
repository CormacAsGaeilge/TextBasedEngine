#pragma once
#include "InteractableCharacter.h"
class PlayerCharacter :
	public InteractableCharacter
{
public:
	PlayerCharacter(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<std::unique_ptr<DynamicItem>> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft, DynamicItem equippedRight);
	~PlayerCharacter();

	void print();
private:

};

