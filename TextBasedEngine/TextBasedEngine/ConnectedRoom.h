#pragma once
#include "DirectionType.h"
class ConnectedRoom
{
public:
	ConnectedRoom(unsigned int roomId, DirectionType direction, bool isLocked);
	~ConnectedRoom();
	unsigned int getRoomId() { return roomId; }
	DirectionType getDirection() { return direction };
	bool getIsLocked() { return isLocked; }
	void setRoomID(unsigned int roomId);
	void setDirection(DirectionType direction);
	void setIsLocked(bool isLocked);
private:
	unsigned int roomId;
	DirectionType direction;
	bool isLocked;
};

