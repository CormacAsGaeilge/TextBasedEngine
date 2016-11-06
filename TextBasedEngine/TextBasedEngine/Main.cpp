#include <iostream>
#include <memory>
#include <vector>
#include <string>

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

unique_ptr<Weapon> createWeapon();
unique_ptr<Consumable> createConsumable();

int main()
{
	vector<unique_ptr<DynamicItem>> itemPouch;
	itemPouch.push_back(createConsumable());
	itemPouch.push_back(createWeapon());

	Character npc(4,"NPC", "Hero of the game", 100,itemPouch,150,true);

	npc.print();

	system("pause");
	return 0;
}

unique_ptr<Consumable> createConsumable() 
{
	return std::make_unique<Consumable>(101, "Potion of Healing", "Heals those who are ill", 5, true, 1, healthPotion, 20);
}

unique_ptr<Weapon> createWeapon()
{
	return std::make_unique<Weapon>(1, "sword", "a basic sword", 15, true, 50, 35, 4);
}
