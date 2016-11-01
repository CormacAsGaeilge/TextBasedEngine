#pragma once
#include "InteractableCharacter.h"
class EnemyCharacter : public InteractableCharacter
{
public:
	EnemyCharacter();
	EnemyCharacter(std::string additionalDialogue);
	~EnemyCharacter();

	std::string getAdditionalDialogue() const { return additionalDialogue; }

	void setAdditionalDialogue(std::string additionalDialogue);

private:
	std::string additionalDialogue;
};

