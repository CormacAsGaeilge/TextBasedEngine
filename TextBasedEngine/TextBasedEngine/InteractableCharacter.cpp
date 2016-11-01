#include "InteractableCharacter.h"

InteractableCharacter::InteractableCharacter(bool equippedLeft, bool equippedRight)
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

void InteractableCharacter::setLeftEquip(bool equippedLeft)
{
	InteractableCharacter::equippedLeft = (equippedLeft != false) ? equippedLeft : true;
}

void InteractableCharacter::setRightEquip(bool equippedRight)
{
	InteractableCharacter::equippedRight = (equippedRight != false) ? equippedRight : true;
}
