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
	//ConnectedRoom::roomId = (roomId > -1) ? roomId : 1;
	ConnectedRoom::roomId = roomId;
}

void ConnectedRoom::setDirection(DirectionType direction)
{
	ConnectedRoom::direction = direction;
}

void ConnectedRoom::setIsLocked(bool isLocked)
{
	ConnectedRoom::isLocked = isLocked;
}

std::string ConnectedRoom::directionToString()
{
	int dir = ConnectedRoom::getDirection();
	switch (dir)
	{
	case 0:
		return "north";
	case 1:
		return "northeast";
	case 2:
		return "east";
	case 3:
		return "southeast";
	case 4:
		return "south";
	case 5:
		return "southwest";
	case 6:
		return "west";
	case 7:
		return "northwest";
	default:
		return "error";
	}
}