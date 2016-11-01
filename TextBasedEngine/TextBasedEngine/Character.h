#pragma once
#include "Object.h"
class Character : public Object
{
public:
	Character(unsigned int health, unsigned int itemPouch, unsigned int wallet, bool state);
	Character();
	~Character();

	unsigned int getHealth() const { return health; }
	unsigned int getItemPouch() const { return itemPouch; }
	unsigned int getWallet() const { return wallet; }
	bool getState() { return state; }

	void setHealth(unsigned int health);
	void setItemPouch(unsigned int itemPouch);
	void setWallet(unsigned int wallet);
	void setState(bool state);

private:
	unsigned int health;
	unsigned int itemPouch;
	unsigned int wallet;
	bool state;
};

