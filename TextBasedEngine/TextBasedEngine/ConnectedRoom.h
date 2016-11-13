/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "DirectionType.h"
#include <string>
class ConnectedRoom
{
public:
	ConnectedRoom(unsigned int roomId, DirectionType direction, bool isLocked);
	~ConnectedRoom();
	unsigned int getRoomId() { return roomId; }
	DirectionType getDirection() { return direction; }
	bool getIsLocked() { return isLocked; }
	void setRoomID(unsigned int roomId);
	void setDirection(DirectionType direction);
	void setIsLocked(bool isLocked);
	std::string directionToString();
private:
	unsigned int roomId;
	DirectionType direction;
	bool isLocked;
};

