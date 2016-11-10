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
	cout << "***************Start of Room***************\nName:\t" << Room::getName() << endl;
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