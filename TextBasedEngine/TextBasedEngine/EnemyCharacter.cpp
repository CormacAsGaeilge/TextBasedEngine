#include "EnemyCharacter.h"

EnemyCharacter::EnemyCharacter(std::string additionalDialogue)
{
	setAdditionalDialogue(additionalDialogue);
}

EnemyCharacter::EnemyCharacter()
{

}

EnemyCharacter::~EnemyCharacter()
{

}

void EnemyCharacter::setAdditionalDialogue(std::string additionalDialogue)
{
	EnemyCharacter::additionalDialogue = (additionalDialogue.length() > 8) ? additionalDialogue : "default dialogue";
}
