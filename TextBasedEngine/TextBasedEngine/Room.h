#pragma once
#include "Object.h"
#include "DirectionType.h"
#include "DynamicItem.h"
#include "InteractableCharacter.h"
#include "Scenary.h"
#include "ConnectedRoom.h"
#include <vector>


class Room : public Object
{
	

public:
	Room(unsigned int id, std::string name, std::string description, std::vector<DynamicItem*> items, std::vector<InteractableCharacter*> characters, std::vector<Scenary*> scenary, std::vector<ConnectedRoom> connectedRooms);
	~Room();
	std::vector<DynamicItem*> getItems() { return items; }
	std::vector<InteractableCharacter*> getCharacters() { return characters; }
	std::vector<Scenary*> getScenary() { return scenary; }
	std::vector<ConnectedRoom> getConnectedRooms() { return connectedRooms; }
	void setItems(std::vector<DynamicItem*>);
	void setCharacters(std::vector<InteractableCharacter*>);
	void setScenary(std::vector<Scenary*>);
	void setConnectedRooms(std::vector<ConnectedRoom>);
private:
	std::vector<DynamicItem*> items;
	std::vector<InteractableCharacter*> characters;
	std::vector<Scenary*> scenary;
	std::vector<ConnectedRoom> connectedRooms;
	 
};

