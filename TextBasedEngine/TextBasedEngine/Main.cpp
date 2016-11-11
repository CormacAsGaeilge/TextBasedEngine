#pragma region Includes

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

#pragma endregion

#pragma region Initialisation of Methods

using namespace std;

Weapon* createWeapon(unsigned int id, string name, string desc, int val, bool state, int uses, int atk, int def, int spd);
Consumable* createConsumable(unsigned int id, string name, string desc, int val, bool state, int uses, ConsumableType consType, int effectVal);
Key* createKey(unsigned int id, string name, string desc, int val, bool state, int uses, unsigned int lockId);

Character* createNPC(unsigned int id, string name, std::string description, unsigned int health, vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight);
EnemyCharacter* createEnemy(unsigned int id, string name, std::string description, unsigned int health, vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight, string additionalDialogue);
PlayerCharacter* createPlayer(unsigned int id, string name, std::string description, unsigned int health, vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight);

Scenary* createScenary(unsigned int id, std::string name, std::string description, std::string additionalDialogue, bool state);

DynamicItem* populateItem(string itemAsString, string delimiter);
void populateItemVector(vector<DynamicItem*>& dynamicItems, vector<string>items, string delimiter);
void populateCharacterVector(vector<Character*>& characterVector, vector<string> characters, string delimiter);
void populateScenaryVector(vector<Scenary*>& scenaryVector, vector<string> scenaryPieces, string delimiter);
void poulateConnectedRoomVector(vector<ConnectedRoom>& cRoomVector, vector<string> cRooms, string delimiter);

DirectionType getDirection(int x);
vector<Room> loadGameFromFile();


size_t getRoomIdWithPlayer(vector<Room>& allRooms);
Character* getPlayer(Room& currentRoom);


/***Referenced Code Start***/
bool to_bool(string str);
vector<string> split(string data, string delimiter);

/***Referenced Code End***/

#pragma endregion

int main()
{
	vector<Room> allRooms = loadGameFromFile();
	//allRooms[0].print();
	Room *currentRoom = &allRooms[getRoomIdWithPlayer(allRooms)];
	currentRoom->print();



	system("pause");
	return 0;

	#pragma region Example of text file format

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
	scen~scen~scen~scene
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

	#pragma endregion

}

size_t getRoomIdWithPlayer(vector<Room>& allRooms)
{
	size_t size = allRooms.size();
	for (size_t i=0; i<size; i++)
	{
		Character* c;
		c = getPlayer(allRooms[i]);
		if (c != NULL)
			return i;
	}
	return NULL;
}

Character* getPlayer(Room& currentRoom)
{
	vector<Character*> chars = currentRoom.getCharacters();
	for (Character* c : chars)
	{
		if (c->getId() == 1)
			return c;
	}
	return NULL;
}

void changeRoom(vector<Room>& allRooms, unsigned int currentRoomId, unsigned int destinationRoomId, DirectionType direction)
{
	vector<ConnectedRoom> cRooms = allRooms[currentRoomId].getConnectedRooms();
	for (ConnectedRoom cR : cRooms)
	{
		if (cR.getRoomId() == destinationRoomId)
		{
			if (cR.getDirection() == direction)
			{
				Character* player = getPlayer(allRooms[currentRoomId]);
				allRooms[destinationRoomId].addCharacter(player);
				allRooms[currentRoomId].removeCharacter(player->getId());
			}
			else
			{
				cout << "No valid room in that direction" << endl;
			}
		}
	}
}










void poulateConnectedRoomVector(vector<ConnectedRoom>& cRoomVector, vector<string> cRooms,string delimiter)
{
	stringstream ss;
	int dir;
	unsigned int roomId;
	DirectionType direction;
	bool isLocked;

	for (string s : cRooms)
	{
		vector<string> connectedRoom = split(s, delimiter);
		ss << connectedRoom[0];
		ss >> roomId;
		ss.clear();
		ss << connectedRoom[1];
		ss >> dir;
		ss.clear();
		direction = getDirection(dir);
		isLocked = to_bool(connectedRoom[2]);
		cRoomVector.push_back(ConnectedRoom(roomId, direction, isLocked));
	}
}

DirectionType getDirection(int x)
{
	switch (x) {
	case 0 :
		return North;
	case 1 :
		return NorthEast;
	case 2 :
		return East;
	case 3 :
		return SouthEast;
	case 4 :
		return South;
	case 5 :
		return SouthWest;
	case 6 :
		return West;
	case 7 :
		return NorthWest;
	default:
		return North;
	}
}

void populateScenaryVector(vector<Scenary*>& scenaryVector, vector<string> scenaryPieces, string delimiter)
{
	/*
	1 | table | a varnished table | it is covered in old cutlery | true
	*/

	stringstream ss;
	unsigned int sceneId;
	string name, desc, additionalDialogue;
	bool state;

	for (string s : scenaryPieces)
	{
		vector<string> scenaryPiece = split(s, delimiter);
		ss << scenaryPiece[0];
		ss >> sceneId;
		ss.clear();
		name = scenaryPiece[1];
		desc = scenaryPiece[2];
		additionalDialogue = scenaryPiece[3];
		state = to_bool(scenaryPiece[4]);
		scenaryVector.push_back(createScenary(sceneId, name, desc, additionalDialogue, state));
	}
}

void populateCharacterVector(vector<Character*>& characterVector, vector<string> characters, string delimiter)
{
	/*
	***Characters***
	char~char~char~char
	plr|id|name|des|health|items|wallet|state|leftHand|rightHand~
	or
	enemy|id|name|des|health|items|wallet|state|leftHand|rightHand~
	or
	npc|id|name|des|health|items|wallet|state|leftHand|rightHand~
	*/


	stringstream ss;
	int health, wallet;
	unsigned int charId;
	string type, name, desc, leftHand, rightHand;
	bool state, onlyOne = true;
	vector<DynamicItem*> dynamicItems;

	for (string s : characters)
	{

		vector<string> character = split(s, delimiter);
		character[0] = type;
		ss << character[1];
		ss >> charId;
		ss.clear();
		name = character[2];
		desc = character[3];
		ss << character[4];
		ss >> health;
		ss.clear();
		vector<DynamicItem*> dynamicItems;
		vector<string> items = split(character[5], "#");
		populateItemVector(dynamicItems, items, ",");
		ss << character[6];
		ss >> wallet;
		ss.clear();
		state = to_bool(character[7]);
		leftHand = character[8];
		rightHand = character[9];
		if (type == "plr" && onlyOne == true)
		{
			//create Player
			characterVector.push_back(createPlayer(charId, name, desc, health, dynamicItems, wallet, state, populateItem(leftHand, ","), populateItem(rightHand, ",")));
			onlyOne = false;
		}
		else if (type == "enemy")
		{
			//create Enemy
			string additionalDialogue = character[8];
			characterVector.push_back(createEnemy(charId, name, desc, health, dynamicItems, wallet, state, populateItem(leftHand, ","), populateItem(rightHand, ","), additionalDialogue));
		}
		else
		{
			//create NPC
			characterVector.push_back(createNPC(charId, name, desc, health, dynamicItems, wallet, state, populateItem(leftHand, ","), populateItem(rightHand, ",")));
		}
	}
}

void populateItemVector(vector<DynamicItem*>& dynamicItems, vector<string>items, string delimiter)
{
	for (string s : items)
		dynamicItems.push_back(populateItem(s, delimiter));
}

DynamicItem* populateItem(string itemAsString, string delimiter)
{
	stringstream ss;
	int atk, def, spd, effectVal;
	unsigned int itemId, lockId, val, uses;
	string name, desc;
	bool state;
	ConsumableType consType;

	vector<string> item = split(itemAsString, delimiter);

	ss << item[0];
	ss >> itemId;
	ss.clear();
	name = item[1];
	desc = item[2];
	ss << item[3];
	ss >> val;
	ss.clear();
	state = to_bool(item[4]);
	ss << item[5];
	ss >> uses;
	ss.clear();


	if (item.size() == 7)
	{
		//create Key
		lockId = to_bool(item[6]);
		return createKey(itemId, name, desc, val, state, uses, lockId);
	}
	else if (item.size() == 8)
	{
		//create Consumable
		/*ss << item[6];
		ss >> consType;*/
		consType = healthPotion;
		ss << item[7];
		ss >> effectVal;
		ss.clear();
		return createConsumable(itemId, name, desc, val, state, uses, consType, effectVal);
	}
	else if (item.size() == 9)
	{
		//create Weapon
		ss << item[6];
		ss >> atk;
		ss.clear();
		ss << item[7];
		ss >> def;
		ss.clear();
		ss << item[8];
		ss >> spd;
		ss.clear();
		return createWeapon(itemId, name, desc, val, state, uses, atk, def, spd);
	}
	else
	{
		return new DynamicItem(itemId, name, desc, val, state, uses);
	}
}

Consumable* createConsumable(unsigned int id, string name, string desc, int val, bool state, int uses, ConsumableType consType, int effectVal)
{
	return new Consumable(id, name, desc, val, state, uses,  consType, effectVal);
}

Weapon* createWeapon(unsigned int id, string name, string desc, int val, bool state, int uses, int atk, int def, int spd)
{
	return new Weapon(id, name, desc, val, state, uses, atk, def,spd);
}

Key* createKey(unsigned int id, string name, string desc, int val, bool state, int uses, unsigned int lockId )
{
	return new Key(id, name, desc, val, state, uses, lockId);
}

Character* createNPC(unsigned int id, string name, std::string description, unsigned int health, vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight)
{
	return new Character(id, name, description, health, itemPouch, wallet, state, equippedLeft, equippedRight);
}

EnemyCharacter* createEnemy(unsigned int id, string name, std::string description, unsigned int health, vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight, string additionalDialogue)
{
	return new EnemyCharacter(id, name, description, health, itemPouch, wallet, state, equippedLeft, equippedRight, additionalDialogue);
}

PlayerCharacter* createPlayer(unsigned int id, string name, std::string description, unsigned int health, vector<DynamicItem*> itemPouch, unsigned int wallet, bool state, DynamicItem* equippedLeft, DynamicItem* equippedRight)
{
	return new PlayerCharacter(id,name,description,health,itemPouch,wallet,state,equippedLeft,equippedRight);
}

Scenary* createScenary(unsigned int id, std::string name, std::string description, std::string additionalDialogue, bool state)
{
	return new Scenary(id, name, description, additionalDialogue, state);
}

vector<Room> loadGameFromFile()
{
	stringstream ss;
	unsigned int roomId = 0;
	string name;
	string description;
	string itemsString;
	string charString;
	string sceneString;
	string cRoomString;

	vector<Room> allRooms;

	/******************************Code by Maik Beckmann from http://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c *********************************/

	ifstream inFile("c:/temp/game.txt");
	string gameFile((std::istreambuf_iterator<char>(inFile)),
		(std::istreambuf_iterator<char>()));
	
	cout << gameFile;

	
	vector<string> rooms = split(gameFile, "/");
	

	for (string s : rooms)
	{
		vector<string> roomVar = split(s, "-");
		//Break down Room

		ss >> roomVar[0];
		ss << roomId;
		ss.clear();
		name = roomVar[1];
		description = roomVar[2];
		itemsString = roomVar[3];
		charString = roomVar[4];
		sceneString = roomVar[5];
		cRoomString = roomVar[6];

		//Break down items
		vector<DynamicItem*> dynamicItems;
		vector<string> items = split(itemsString, "~");
		populateItemVector(dynamicItems, items, "|");

		vector<Character*> characterVector;
		vector<string> characters = split(charString, "~");
		populateCharacterVector(characterVector, characters, "|");

		vector<Scenary*> scenaryVector;
		vector<string> scenary = split(sceneString, "~");
		for (string s : scenary)
			cout << s << endl;
		populateScenaryVector(scenaryVector, scenary, "|");

		vector<ConnectedRoom> cRoomVector;
		vector<string> cRoom = split(cRoomString, "~");
		poulateConnectedRoomVector(cRoomVector, cRoom, "|");


		allRooms.push_back(Room(roomId, name, description,
			dynamicItems,
			characterVector,
			scenaryVector,
			cRoomVector));
	}
	
	inFile.close();

	return allRooms;
}


/******************************Code by Georg Fritzsche from http://stackoverflow.com/questions/3613284/c-stdstring-to-boolean *********************************/
bool to_bool(string str) 
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	istringstream is(str);
	bool b;
	is >> std::boolalpha >> b;
	is.clear();
	return b;
}

/******************************Code by Niall McGuinness from moodle*********************************/
vector<string> split(string data, string delimiter)
{
	vector<string> outVector;
	string strElement;
	size_t oldPos = -1;
	size_t pos = data.find(delimiter, oldPos + 1);
	while (pos != string::npos)
	{
		strElement = data.substr(oldPos + 1, pos - oldPos - 1);
		outVector.push_back(strElement);
		oldPos = pos;
		pos = data.find(delimiter, oldPos + 1);
	}
	return outVector;
}
