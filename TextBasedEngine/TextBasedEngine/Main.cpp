#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>

#include "Object.h"

#include "Character.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "InteractableCharacter.h"

#include "Item.h"
#include "DynamicItem.h"
#include "Weapon.h"
#include "Key.h"
#include "Consumable.h"
#include "ConsumableType.h"
#include "Scenary.h"
#include "Room.h"

using namespace std;

Weapon* createWeapon();
Consumable* createConsumable();
void loadRoomFromFile();

int main()
{
	loadRoomFromFile();
	/*vector<DynamicItem*> itemPouch;
	Weapon sword(1, "sword", "a basic sword", 15, true, 50, 35, 4);
	Weapon shield(1, "shield", "a basic shield", 15, true, 50, 4, 40);
	PlayerCharacter player(1,"Player", "Hero of the game", 100, itemPouch, 150, true,sword,shield);

	vector<DynamicItem*> items;
	items.push_back(createConsumable());
	items.push_back(createWeapon());

	vector<InteractableCharacter*> characters;
	characters.push_back(&player);


	Scenary cupboard(1, "cupboard", "A simple cupboard", "It is old and worn.", true);



	vector<Scenary*> scenary;
	scenary.push_back(&cupboard);

	vector<ConnectedRoom> connectedRooms;

	Room house(5, "House", "Starting House", items, characters, scenary, connectedRooms);*/

	system("pause");
	return 0;
}

Consumable* createConsumable() 
{
	return new Consumable(1, "Potion of Healing", "Heals those who are ill", 5, true, 1, healthPotion, 20);
}

Weapon* createWeapon()
{
	return new Weapon(1, "sword", "a basic sword", 15, true, 50, 35, 4);
}

void loadRoomFromFile()
{
	ifstream inFile;
	inFile.open("c:/temp/banterRoom.txt");

	int id;
	string name;
	string description;
	std::vector<DynamicItem*> item;
	std::vector<InteractableCharacter*> iChar;
	std::vector<Scenary*> scene;
	std::vector<ConnectedRoom> cRoom;


	while (!inFile.eof())
	{
		inFile >> id;
		inFile >> name;
		inFile >> description;
	}

	Room room(id, name, description, item, iChar, scene, cRoom);

	room.print();

	inFile.close();
}