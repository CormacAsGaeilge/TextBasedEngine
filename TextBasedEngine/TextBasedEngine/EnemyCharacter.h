/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "Character.h"
class EnemyCharacter : public Character
{
public:
	EnemyCharacter();
	EnemyCharacter(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight, std::string additionalDialogue);
	virtual ~EnemyCharacter();

	std::string getAdditionalDialogue() const { return additionalDialogue; }

	void setAdditionalDialogue(std::string additionalDialogue);

private:
	std::string additionalDialogue;
};

