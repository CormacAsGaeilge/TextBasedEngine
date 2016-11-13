#pragma once
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

class Engine
{
public:
	void run(Character* player, Room* currentRoom, vector<Room> allRooms, vector<int> roomIdVisited);
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

private:

protected:

	
};



