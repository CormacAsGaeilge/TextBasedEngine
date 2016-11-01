#pragma once
#include "DynamicItem.h"
class Key : public DynamicItem
{
public:
	Key(unsigned int lockId);
	Key();
	~Key();

	unsigned int getLockId() const { return lockId; }

	void setLockId(unsigned int lockId);

private:
	unsigned int lockId;
};

