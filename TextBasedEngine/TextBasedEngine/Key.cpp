#include "Key.h"

Key::Key(unsigned int id, std::string name, std::string description, unsigned int value, bool state, unsigned int uses, unsigned int lockId)
	: DynamicItem(id,name,description,value,state,uses)
{
	setLockId(lockId);
}

Key::Key()
{

}

Key::~Key()
{

}

void Key::setLockId(unsigned int lockId)
{
	Key::lockId = (lockId > 0) ? lockId : 1;
}
