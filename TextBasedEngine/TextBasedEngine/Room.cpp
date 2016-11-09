#include "Room.h"



Room::Room(unsigned int id, std::string name, std::string description, std::vector<DynamicItem*> items, std::vector<InteractableCharacter*> characters, std::vector<Scenary*> scenary, std::vector<ConnectedRoom> connectedRooms)
	:Object(id,name,description)
{
	setItems(items);
	setCharacters(characters);
	setScenary(scenary);
	setConnectedRooms(connectedRooms);
}


Room::~Room()
{
}

void Room::setItems(std::vector<DynamicItem*> items)
{
	for (DynamicItem* ptr : items)
		Room::items.push_back(ptr);
}

void Room::setCharacters(std::vector<InteractableCharacter*> characters)
{
	for (InteractableCharacter* ptr : characters)
		Room::characters.push_back(ptr);
}

void Room::setScenary(std::vector<Scenary*> scenary)
{
	for (Scenary* ptr : scenary)
		Room::scenary.push_back(ptr);
}

void Room::setConnectedRooms(std::vector<ConnectedRoom> connectedRooms)
{
	for (ConnectedRoom room : connectedRooms)
		Room::connectedRooms.push_back(room);
}