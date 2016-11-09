#pragma once
#include "Character.h"
#include "DynamicItem.h"
class InteractableCharacter : public Character
{
public:
	InteractableCharacter();
	InteractableCharacter(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft, DynamicItem equippedRight);
	~InteractableCharacter();
	
	DynamicItem getLeftEquip() { return equippedLeft; }
	DynamicItem getRightEquip() { return equippedRight; }

	void setLeftEquip(DynamicItem equippedLeft) { InteractableCharacter::equippedLeft = equippedLeft; }
	void setRightEquip(DynamicItem equippedRight) { InteractableCharacter::equippedRight = equippedRight; }

private:
	DynamicItem equippedLeft;
	DynamicItem equippedRight;
};

