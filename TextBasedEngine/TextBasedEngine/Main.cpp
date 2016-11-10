#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

#include "Object.h"

#include "Character.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"

#include "Item.h"
#include "DynamicItem.h"
#include "Weapon.h"
#include "Key.h"
#include "Consumable.h"
#include "ConsumableType.h"
#include "Scenary.h"
#include "Room.h"

using namespace std;

Weapon* createWeapon(unsigned int id, string name, string desc, int val, bool state, int uses, int atk, int def);
Consumable* createConsumable(unsigned int id, string name, string desc, int val, bool state, int uses, ConsumableType consType, int effectVal);
void loadRoomsFromFile();
std::vector<std::string> split(std::string data, std::string delimiter);
int main()
{
	//loadRoomsFromFile();
	//setCurrentRoom();


	std::cout << "********* Using std::string::find() with a char *********" << std::endl;
	//using std::string::find() with a char
	string data = "a,b,c,d,e";
	size_t pos = data.find(',', 0);
	if (pos != std::string::npos)
		std::cout << "Found at:" << pos << std::endl;
	else
		std::cout << "Could not find the character!" << std::endl;

	std::cout << "********* Writing a split method to parse a string using a delimiter *********" << std::endl;
	//writing a split method to parse a string using a delimiter


	//convert string to int
	stringstream ss;
	vector<string> Rooms = split("file", "/");
	unsigned int roomId;
	string name;
	string description;
	string itemsString;
	string charString;
	string sceneString;
	string cRoomString;

	for (string s : Rooms)
	{
		vector<string> roomVar = split(s, "-");
		//Break down Room
		
		ss >> roomVar[0];
		ss << roomId;
		name = roomVar[1];
		description = roomVar[2];
		itemsString = roomVar[3];
		charString = roomVar[4];
		sceneString = roomVar[5];
		cRoomString = roomVar[6];

		//Break down items
		vector<DynamicItem*> dynamicItems;


		vector<string> items = split(itemsString, "~");

		int val, atk, def, effectVal, uses;
		unsigned int itemId, lockId;
		string name, desc;
		bool state;
		ConsumableType consType;

		for (string s : items)
		{

			vector<string> item = split(s, "|");
			if (item.size == 6)
			{
				//create DynamicItem
			}
			else if (item.size == 7)
			{
				
				//create Key
				ss << item[0];
				ss >> itemId;
				name = item[1];
				desc = item[2];
				ss << item[3];
				ss >> val;
				state = to_bool(item[4]);
				ss << item[5];
				ss >> uses;
				lockId = to_bool(item[6]);
				dynamicItems.push_back(createKey(itemId, name, desc, val, state, uses, lockId));
			}
			/*else if (second last item in vector is = number)
			{
				//create Weapon
				createWeapon(id, name, desc, val, state, uses, atk, def);
			}
			else
			{
				//create Consumable
				createConsumable(id, name, desc, val, state, uses, consType, effectVal);
			}
			*/
		}

	}

	/*
	***Rooms***
	room/room/room/room

	1-name-description-items-Char-Scen-cRooms/2-name-description-items-Char-Scen-cRooms/

	***Items***
	item~item~item~item
	id|name|desc|val|state|uses~
	or
	id|name|desc|val|state|uses|consType|effectVal~
	or
	id|name|desc|val|state|uses|atk|def~
	or
	id|name|desc|val|state|uses|lockId~

	***Characters***
	char~char~char~char
	plr|id|name|des|health|items|wallet|state|leftHand|rightHand~
	or
	enemy|id|name|des|health|items|wallet|state|leftHand|rightHand~
	or
	npc|id|name|des|health|items|wallet|state|leftHand|rightHand~
	
		***Character items***
		item#item#item#item
		id,name,desc,val,state,uses#
		or
		id,name,desc,val,state,uses,consType,effectVal#
		or
		id,name,desc,val,state,uses,atk,def#
		or
		id,name,desc,val,state,uses,lockId#

	***Scenary***
	scen~scen~scen~scen
	id|name|desc|additionalDialogue|state~

	***cRooms***
	roomId|direction|isLocked~
	*/







	/*vector<DynamicItem*> itemPouch;
	Weapon sword(1, "sword", "a basic sword", 15, true, 50, 35, 4);
	Weapon shield(1, "shield", "a basic shield", 15, true, 50, 4, 40);
	itemPouch.push_back(createConsumable());
	itemPouch.push_back(createWeapon());

	PlayerCharacter player(1,"Player", "Hero of the game", 100, itemPouch, 150, true,sword,shield);


	player.print();*/
	/*vector<DynamicItem*> items;
	items.push_back(createConsumable());
	items.push_back(createWeapon());

	vector<InteractableCharacter*> characters;
	characters.push_back(&player);


	Scenary cupboard(1, "cupboard", "A simple cupboard", "It is old and worn.", true);



	vector<Scenary*> scenary;
	scenary.push_back(&cupboard);

	vector<ConnectedRoom> connectedRooms;

	Room house(5, "House", "Starting House", items, characters, scenary, connectedRooms);
*/
	system("pause");
	return 0;
}


bool to_bool(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	istringstream is(str);
	bool b;
	is >> std::boolalpha >> b;
	return b;
}



Consumable* createConsumable(unsigned int id, string name, string desc, int val, bool state, int uses, ConsumableType consType, int effectVal)
{
	return new Consumable(id, name, desc, val, state, uses,  consType, effectVal);
}

Weapon* createWeapon(unsigned int id, string name, string desc, int val, bool state, int uses, int atk, int def)
{
	return new Weapon(id, name, desc, val, state, uses, atk, def);
}

Key* createKey(unsigned int id, string name, string desc, int val, bool state, int uses, unsigned int lockId )
{
	return new Key(id, name, desc, val, state, uses, lockId);
}

void loadRoomsFromFile()
{
	ifstream inFile;
	inFile.open("c:/temp/banterRoom.txt");

	int id;
	string name;
	string description;
	std::vector<DynamicItem*> item;
	std::vector<Character*> Char;
	std::vector<Scenary*> scene;
	std::vector<ConnectedRoom> cRoom;

	while (!inFile.eof())
	{
		inFile >> id;
		inFile >> name;
		inFile >> description;
	}

	Room room(id, name, description, item, Char, scene, cRoom);

	room.print();

	inFile.close();
}

void createItemVector()
{
	vector<DynamicItem*> itemVec;

}

std::vector<std::string> split(std::string data, std::string delimiter)
{
	std::vector<std::string> outVector;
	std::string strElement;
	std::size_t oldPos = -1;
	std::size_t pos = data.find(delimiter, oldPos + 1);
	while (pos != std::string::npos)
	{
		strElement = data.substr(oldPos + 1, pos - oldPos - 1);
		outVector.push_back(strElement);
		oldPos = pos;
		pos = data.find(delimiter, oldPos + 1);
	}
	return outVector;
}
