/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "Object.h"
#include "Weapon.h"
#include <vector>
#include <memory>
class Character : public Object
{
public:
	Character(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state,
		DynamicItem* equippedLeft, DynamicItem* equippedRight);
	Character();
	virtual ~Character();

	unsigned int getHealth() const { return health; }
	std::vector<DynamicItem*> getItemPouch() const { return itemPouch; }
	unsigned int getWallet() const { return wallet; }
	bool getState() { return state; }
	DynamicItem* getLeftEquip() { return equippedLeft; }
	DynamicItem* getRightEquip() { return equippedRight; }

	void setHealth(unsigned int health);
	void setItemPouch(std::vector<DynamicItem*> itemPouch);
	void setWallet(unsigned int wallet);
	void setState(bool state);
	void setLeftEquip(DynamicItem* equippedLeft) { Character::equippedLeft = equippedLeft; }
	void setRightEquip(DynamicItem* equippedRight) { Character::equippedRight = equippedRight; }
	void pickUp(DynamicItem* item);
	virtual void print();
	void printItemPouch();

private:
	unsigned int health;
	std::vector<DynamicItem*> itemPouch;
	unsigned int wallet;
	bool state;
	DynamicItem *equippedLeft, *equippedRight;
};

