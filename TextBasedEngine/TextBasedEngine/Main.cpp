#include <iostream>

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

int main()
{
	Weapon sword(1,"sword","a basic sword", 15, true, 50, 35, 4);
	Weapon shield(2, "shield", "a basic shield", 10, true, 60, 2, 40);
	Consumable healthPotion(101, "Potion of Healing", "Heals those who are ill", 5, true, 1, healthPotion, 20);
	vector<DynamicItem> itemPouch;
	itemPouch.push_back(healthPotion);



	PlayerCharacter hero(4,"Cormac", "Hero of the game", 100,itemPouch,150,true, shield, sword);

	hero.print();

	system("pause");
	return 0;
}