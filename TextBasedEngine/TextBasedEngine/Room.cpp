/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Room.h"
#include <iostream>
#include <string>
using namespace std;


Room::Room(unsigned int id, string name, string description, vector<DynamicItem*> items, vector<Character*> characters,
	vector<Scenary*> scenary, vector<ConnectedRoom> connectedRooms)
	:Object(id,name,description)
{
	setItems(items);
	setCharacters(characters);
	setScenary(scenary);
	setConnectedRooms(connectedRooms);
}


Room::~Room()
{
	/*for (DynamicItem* ptr : Room::items)
		delete ptr;
	items.clear();
	for (Character* ptr : Room::characters)
		delete ptr;
	characters.clear();
	for (Scenary* ptr : Room::scenary)
		delete ptr;
	scenary.clear();*/
}

void Room::setItems(vector<DynamicItem*> items)
{
	for (DynamicItem* ptr : items)
		Room::items.push_back(ptr);
}

void Room::setCharacters(vector<Character*> characters)
{
	for (Character* ptr : characters)
		Room::characters.push_back(ptr);
}

void Room::setScenary(vector<Scenary*> scenary)
{
	for (Scenary* ptr : scenary)
		Room::scenary.push_back(ptr);
}

void Room::setConnectedRooms(vector<ConnectedRoom> connectedRooms)
{
	for (ConnectedRoom room : connectedRooms)
		Room::connectedRooms.push_back(room);
}

void Room::print()
{
	cout << "***************Start of Room***************\nRoom Name:\t" << Room::getName() << endl;
	cout << "Room Description:\n";
	cout << Object::getDescription() << endl;
	cout << "\n\nItems in Room:" << endl;
	Room::printItems();
	cout<< "\n\nScenary in Room:\n";
	Room::printScenary();
	cout << "\n\nPrint Characters in Room:" << endl; 
	Room::printCharacters(); 
	cout << "\n\nPrint Connecting Rooms" << endl;
	Room::printConnectedRooms();
	cout << "\n****************End of Room****************" << endl;
}

void Room::softPrint()
{
	cout << "***************Start of Room***************\nRoom Name:\t" << Room::getName() << endl;
	cout << "Room Description:\n";
	cout << Object::getDescription() << endl;
	Room::printItemNames();
	Room::printScenaryNames();
	Room::printCharacterNames();
	Room::printConnectedRoomNames();
	cout << "\n****************End of Room****************" << endl;
}

void Room::printItemNames()
{
	cout << "Items: There are " << Room::items.size() << "." << endl;
	for (DynamicItem* ptr : Room::getItems())
		cout << "Item Name: " << ptr->getName() << endl;
	cout << "******end of items******" << endl;
}

void Room::printScenaryNames()
{
	cout << "Scenary: There are " << Room::items.size() << "." << endl;
	for (Scenary* ptr : Room::getScenary())
		cout << "Scenary Name: " << ptr->getName() << endl;
	cout << "******end of scenary******" << endl;
}

void Room::printCharacterNames()
{
	cout << "Characters: There are " << Room::items.size() << "." << endl;
	for (Character* ptr : Room::getCharacters())
		cout << "Character Name: " << ptr->getName() << endl;
	cout << "******end of characters******" << endl;
}

void Room::printConnectedRoomNames()
{
	cout << "Connecting rooms: There are " << Room::items.size() << "." << endl;
	cout << "******end of connecting rooms******" << endl;
}

void Room::printItems()
{
	for (DynamicItem* ptr : Room::getItems())
		ptr->print();
}

void Room::printScenary()
{
	for (Scenary* ptr : Room::getScenary())
		ptr->print();
}

void Room::printCharacters()
{
	for (Character* ptr : Room::getCharacters())
		ptr->print();
}

void Room::printConnectedRooms()
{
	for (ConnectedRoom room : Room::getConnectedRooms())
		cout << "Connected Room:\t" << room.getRoomId() << endl;
}

void Room::addCharacter(Character* character)
{
	Room::characters.push_back(character);
}

void Room::addItem(DynamicItem* item)
{
	Room::items.push_back(item);
}

void Room::removeCharacter(unsigned int characterId)
{
	size_t size = Room::characters.size();
	for (size_t i=0; i<size; i++)
	{
		if (Room::characters[i]->getId() == characterId)
		{
			Room::characters.erase(Room::characters.begin() + i);
			i++;
		}
	}

	/*int i = 0;
	for (Character* c : Room::characters)
	{
		if (Room::characters[i]->getId() == characterId)
			Room::characters.erase(Room::characters.begin() + i);
		i++;
	}*/
}

void Room::removeItem(unsigned int itemId)
{
	size_t size = Room::items.size();
	for (size_t i = 0; i<size; i++)
	{
		if (Room::items[i]->getId() == itemId)
		{
			Room::items.erase(Room::items.begin() + i);
			i++;
		}
	}
}