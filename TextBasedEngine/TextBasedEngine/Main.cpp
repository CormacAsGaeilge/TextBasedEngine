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

bool checkIfRoom(vector<Room> allRooms, string noun);
bool checkIfScenary(Room& currentRoom, string noun);
bool checkIfItem(Room& currentRoom, string noun);
bool checkIfCharacter(Room& currentRoom, string noun);
bool checkIfDirection(string s);

DirectionType getDirection(int x);
DirectionType getDirection(string s);

void loadGameFromFile(vector<Room>& allRooms);
string toLowerCase(string s);

size_t getRoomIdWithPlayer(vector<Room>& allRooms);
Character* getPlayer(Room& currentRoom);
void changeRoom(vector<Room>& allRooms, unsigned int currentRoomId, unsigned int destinationRoomId, DirectionType direction);

/***Referenced Code Start***/
bool to_bool(string str);
vector<string> split(string data, string delimiter);

/***Referenced Code End***/
#pragma endregion


int main()
{
	#pragma region Test

	vector<Room> allRooms;
		
	loadGameFromFile(allRooms);
	//allRooms[0].print();
	Room *currentRoom = &allRooms[getRoomIdWithPlayer(allRooms)];
	//currentRoom->print();

	#pragma endregion

	#pragma region Story

	cout << "Now you begin your story." << endl;
	allRooms[0].print();

	#pragma endregion		

	#pragma region Directions

	int check = 0;
	string verb, noun;
	
	while (check != 1)
	{
		cout << "Enter your command: ";
		cin >> verb;
		cin >> noun;


		verb = toLowerCase(verb);
		noun = toLowerCase(noun);
		if (verb == "go")
		{
			if (checkIfDirection(noun))
			{

				DirectionType dir = getDirection(noun);

				//check if more than one room in direction
				unsigned int numOfRooms = 0, destinationId;
				vector<ConnectedRoom*> connectedRoomIds;
				for (ConnectedRoom cR : currentRoom->getConnectedRooms())
				{
					if (cR.getDirection() == dir)
					{
						numOfRooms++;
						connectedRoomIds.push_back(&cR);
					}
					else
						cout << "test" << endl;
				}
				if (numOfRooms == 0)
					cout << "No rooms due " << noun << "." << endl;
				else if (numOfRooms == 1)
				{
					for (ConnectedRoom cR : currentRoom->getConnectedRooms())
					{
						if (cR.getDirection() == dir)
						{
							changeRoom(allRooms, currentRoom->getId(), cR.getRoomId(), dir);
							currentRoom = &allRooms[cR.getRoomId()];
							cout << "You are now in " << currentRoom->getName() <<"." << endl;
						}
					}
				}
				else
				{
					cout << "multiple rooms in this direction" << endl;
					size_t vecSize = connectedRoomIds.size();
					unsigned int i = 0, selectedRoomNumber;
					for (Room r : allRooms)
					{
						if (r.getId() == connectedRoomIds[i]->getRoomId())
						{
							cout << "[" << i << "] - " << r.getName() << endl;
							i++;
						}
					}
					cout << "enter number of room:";
					cin >> selectedRoomNumber;
					destinationId = connectedRoomIds[selectedRoomNumber]->getRoomId();
					changeRoom(allRooms, currentRoom->getId(), destinationId, dir);
				}
			}
			else
				cout << "verb go can only be used with direction" << endl;

		}
		else if (verb == "pickup")
		{
			vector<string> itemRoomList;
			for (DynamicItem* dItem : currentRoom->getItems())
			{
				itemRoomList.push_back(dItem->getName());
			}


			for (int i = 0; i < itemRoomList.size(); i++)
			{
				if (noun == itemRoomList[i])
				{
					cout << "The " << noun << " was added to your inventory" << endl;
					//need to push item to character item pounc
					break;
				}
				else
				{
					cout << "There is no such item here" << endl;
					break;
				}
			}
		}
		else if (verb == "lookat")
		{
			
		}
		else if (verb == "use")
		{
		
		}
		else if (verb == "view")
		{
		
		}
		else if (verb == "help")
		{
			if (noun == "controls")
			{
				cout << "Keywords:" << endl;
				cout << "Go ...\nPickup ...\nLookat ...\nUse ...\nView ..." << endl;
				cout << "Directions:" << endl;
				cout << "North\nWest\nEast\nSouth\nNorthWest\nNorthEast\nSouthWest\nSouthEast" << endl;
			}
			else if (noun == "rooms")
			{
				//write info about rooms and what kind of interactions can be made
				cout << "rooms..." << endl;
			}
			else if (noun == "items")
			{
				//write info about items and what kind of interactions can be made
				cout << "items..." << endl;
			}
			else if (noun == "characters")
			{
				//write info about characters and what kind of interactions can be made
				cout << "characters..." << endl;
			}
			else if (noun == "scenary")
			{
				//write info about scenary and what kind of interactions can be made
				cout << "scenary..." << endl;
			}
			else
			{
				cout << "After the word help type one of the following for more information.\ncontrols\nrooms\nitems\ncharacters\nscenary" << endl;
			}
		}
		else if (verb == "settings")
		{
			if (noun == "quit")
			{
				string quit;
				cout << "Progress will not be saved. IF you wish to save type 'settings save'. Are you sure you wish to quit? [y/n]" << endl;
				cin >> quit;
				if (quit == "y")
				{
					cout << "Game Has Ended" << endl;
					check = 1;
				}
				else
					cout << "canceled quiting" << endl;
			}
			else if (noun == "save")
			{
				//implement save to file
			}
			else if (noun == "load")
			{
				//implement load from file
			}
			else
			{
				cout << "Enter one of the following settings commands:-\nquit\nsave\nload" << endl;
			}
		}
		else
		{
			cout << "No valid verb. Type 'help controls' for a list of all commands" << endl;
		}
	}

	#pragma endregion

	system("pause");
	return 0;
}

#pragma region Character/Room

bool checkIfItem(Room& currentRoom, string noun)
{
	return true;
}

bool checkIfCharacter(Room& currentRoom, string noun)
{
	return true;
}

bool checkIfScenary(Room& currentRoom, string noun)
{
	return true;
}

bool checkIfRoom(vector<Room> allRooms, string noun)
{
	string nameLowerCase;
	for (Room r : allRooms)
	{
		nameLowerCase = toLowerCase(r.getName());
		if (nameLowerCase == noun)
			return true;
	}
	return false;
}

bool checkIfDirection(string s)
{
	if (s == "north")
		return true;
	else if (s == "northeast")
		return NorthEast;
	else if (s == "east")
		return true;
	else if (s == "southeast")
		return SouthEast;
	else if (s == "south")
		return true;
	else if (s == "southwest")
		return true;
	else if (s == "west")
		return true;
	else if (s == "northwest")
		return true;
	else
		return false;
}

size_t getRoomIdWithPlayer(vector<Room>& allRooms)
{
	size_t size = allRooms.size();
	for (size_t i = 0; i<size; i++)
	{
		Character* c;
		c = getPlayer(allRooms[i]);
		if (&c != NULL)
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
				cout << player->getName() << " left " << allRooms[currentRoomId].getName()
					<< " and went to " << allRooms[destinationRoomId].getName() << endl;
			}
			else
			{
				cout << "No valid room in that direction" << endl;
			}
		}
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

DirectionType getDirection(string s)
{
	s = toLowerCase(s);
	
	if (s == "north")
		return North;
	else if (s == "northeast")
		return NorthEast;
	else if (s == "east")
		return East;
	else if (s == "southeast")
		return SouthEast;
	else if (s == "south")
		return South;
	else if (s == "southwest")
		return SouthWest;
	else if (s == "west")
		return West;
	else if (s == "northwest")
		return NorthWest;
	else
		return North;
}

string toLowerCase(string s)
{
	unsigned int length = s.length();
	for (unsigned int i = 0; i<length; i++)
		s[i]=tolower(s[i]);
	return s;
}

#pragma endregion

#pragma region Populate

void poulateConnectedRoomVector(vector<ConnectedRoom>& cRoomVector, vector<string> cRooms, string delimiter)
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

#pragma endregion

#pragma region Create Classes

Consumable* createConsumable(unsigned int id, string name, string desc, int val, bool state, int uses, ConsumableType consType, int effectVal)
{
	return new Consumable(id, name, desc, val, state, uses, consType, effectVal);
}

Weapon* createWeapon(unsigned int id, string name, string desc, int val, bool state, int uses, int atk, int def, int spd)
{
	return new Weapon(id, name, desc, val, state, uses, atk, def, spd);
}

Key* createKey(unsigned int id, string name, string desc, int val, bool state, int uses, unsigned int lockId)
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
	return new PlayerCharacter(id, name, description, health, itemPouch, wallet, state, equippedLeft, equippedRight);
}

Scenary* createScenary(unsigned int id, std::string name, std::string description, std::string additionalDialogue, bool state)
{
	return new Scenary(id, name, description, additionalDialogue, state);
}

#pragma endregion

#pragma region loadGame

void loadGameFromFile(vector<Room>& allRooms)
{
	stringstream ss;
	unsigned int roomId;
	string name;
	string description;
	string itemsString;
	string charString;
	string sceneString;
	string cRoomString;


	/******************************Code by Maik Beckmann from http://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c *********************************/

	ifstream inFile("c:/temp/game.txt");
	string gameFile((std::istreambuf_iterator<char>(inFile)),
		(std::istreambuf_iterator<char>()));
	
	vector<string> rooms = split(gameFile, "/");


	for (string s : rooms)
	{
		vector<string> roomVar = split(s, "-");
		//Break down Room

		ss << roomVar[0];
		ss >> roomId;
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
}

#pragma endregion

#pragma region Sourced Code

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

#pragma endregion