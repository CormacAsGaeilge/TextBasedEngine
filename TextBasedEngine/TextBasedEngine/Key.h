/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "DynamicItem.h"
class Key : public DynamicItem
{
public:
	Key(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, unsigned int lockId);
	Key();
	~Key();

	unsigned int getLockId() const { return lockId; }
	void setLockId(unsigned int lockId);
	void print() override;
	void useItem() override;
private:
	unsigned int lockId;
};

