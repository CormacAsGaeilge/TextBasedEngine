#pragma once
#include "Character.h"
class InteractableCharacter : public Character
{
public:
	InteractableCharacter();
	InteractableCharacter(bool equippedLeft, bool equippedRight);
	~InteractableCharacter();
	
	bool getLeftEquip() { return equippedLeft; }
	bool getRightEquip() { return equippedRight; }

	void setLeftEquip(bool equippedLeft);
	void setRightEquip(bool equippedRight);

private:
	bool equippedLeft;
	bool equippedRight;
};

