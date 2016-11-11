#pragma once
#include "Object.h"
#include "DirectionType.h"
#include "DynamicItem.h"
#include "Character.h"
#include "Scenary.h"
#include "ConnectedRoom.h"
#include <vector>


class Room : public Object
{
	

public:
	Room(unsigned int id, std::string name, std::string description, std::vector<DynamicItem*> items, std::vector<Character*> characters, std::vector<Scenary*> scenary, std::vector<ConnectedRoom> connectedRooms);
	~Room();
	std::vector<DynamicItem*> getItems() { return items; }
	std::vector<Character*> getCharacters() { return characters; }
	std::vector<Scenary*> getScenary() { return scenary; }
	std::vector<ConnectedRoom> getConnectedRooms() { return connectedRooms; }
	void setItems(std::vector<DynamicItem*>);
	void setCharacters(std::vector<Character*>);
	void setScenary(std::vector<Scenary*>);
	void setConnectedRooms(std::vector<ConnectedRoom>);

	void addCharacter(Character*);
	void addItem(DynamicItem*);
	void removeCharacter(unsigned int characterId);
	void removeItem(unsigned int itemId);

	void print();
	void printItems();
	void printScenary();
	void printCharacters();
	void printConnectedRooms();

private:
	std::vector<DynamicItem*> items;
	std::vector<Character*> characters;
	std::vector<Scenary*> scenary;
	std::vector<ConnectedRoom> connectedRooms;
	 
};

