#pragma once
#include "Object.h"
#include "Weapon.h"
#include <vector>
#include <memory>
class Character : public Object
{
public:
	Character(unsigned int id, std::string name, std::string description, unsigned int health, std::vector<DynamicItem*> itemPouch, unsigned int wallet, bool state);
	Character();
	~Character();

	unsigned int getHealth() const { return health; }
	std::vector<DynamicItem*> getItemPouch() const { return itemPouch; }
	unsigned int getWallet() const { return wallet; }
	bool getState() { return state; }

	void setHealth(unsigned int health);
	void setItemPouch(std::vector<DynamicItem*> itemPouch);
	void setWallet(unsigned int wallet);
	void setState(bool state);
	void print();
	void printItemPouch();

private:
	unsigned int health;
	std::vector<DynamicItem*> itemPouch;
	unsigned int wallet;
	bool state;
};

