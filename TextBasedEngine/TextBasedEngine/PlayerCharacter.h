#pragma once
#include "Character.h"
class PlayerCharacter :
	public Character
{
public:
	PlayerCharacter(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem equippedLeft, DynamicItem equippedRight);
	virtual ~PlayerCharacter();

	void print() override;
	void interaction(std::string action, DynamicItem item);
	void pickUp(DynamicItem item);
	void search();
	void use(DynamicItem item);
	void interact(DynamicItem item);
	void lookAt(DynamicItem item);
private:
	std::string action;
	std::string object;
	DynamicItem item;
};

