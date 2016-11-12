/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "ConnectedRoom.h"

ConnectedRoom::ConnectedRoom(unsigned int roomId, DirectionType direction, bool isLocked)
{
	setRoomID(roomId);
	setDirection(direction);
	setIsLocked(isLocked);
}

ConnectedRoom::~ConnectedRoom()
{
}

void ConnectedRoom::setRoomID(unsigned int roomId)
{
	ConnectedRoom::roomId = (roomId > 0) ? roomId : 1;
}

void ConnectedRoom::setDirection(DirectionType direction)
{
	ConnectedRoom::direction = direction;
}

void ConnectedRoom::setIsLocked(bool isLocked)
{
	ConnectedRoom::isLocked = isLocked;
}