#pragma once
#include "Item.h"
class DynamicItem : public Item
{
public:
	DynamicItem(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses);
	DynamicItem();
	virtual ~DynamicItem();

	bool getState() { return state; }
	unsigned int getUses() { return uses; }

	void setState(bool state);
	void setUses(unsigned int uses);
	virtual void print() override;
private:
	bool state;
	unsigned int uses;

};

