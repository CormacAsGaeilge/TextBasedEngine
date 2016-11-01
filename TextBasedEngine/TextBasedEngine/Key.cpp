#include "Key.h"

Key::Key(unsigned int lockId)
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
