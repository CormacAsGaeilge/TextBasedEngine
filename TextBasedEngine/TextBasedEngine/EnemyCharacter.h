#pragma once
#include "InteractableCharacter.h"
class EnemyCharacter : public InteractableCharacter
{
public:
	EnemyCharacter();
	EnemyCharacter(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft, DynamicItem equippedRight, std::string additionalDialogue);
	~EnemyCharacter();

	std::string getAdditionalDialogue() const { return additionalDialogue; }

	void setAdditionalDialogue(std::string additionalDialogue);

private:
	std::string additionalDialogue;
};

