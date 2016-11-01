#pragma once
#include "Item.h"
class DynamicItem : public Item
{
public:
	DynamicItem(bool state);
	DynamicItem();
	~DynamicItem();

	bool getState() { return state; }

	void setState(bool state);

private:
	bool state;

};

