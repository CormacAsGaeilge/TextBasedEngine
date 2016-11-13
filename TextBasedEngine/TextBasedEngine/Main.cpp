/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma region Includes

#include "Engine.h"
#include <iostream>
#include <vector>

#pragma endregion

using namespace std;

#pragma region Main Game

int main()
{
	Engine engine;
	
	vector<Room> allRooms;
	engine.loadGameFromFile(allRooms);
	Room *currentRoom = &allRooms[engine.getRoomIdWithPlayer(allRooms)];
	vector<int> roomIdVisited;
	roomIdVisited.push_back(currentRoom->getId());
	Character* player = engine.getPlayer(*currentRoom);
	engine.run(player,currentRoom,allRooms,roomIdVisited);
	system("pause");
	return 0;
}

#pragma endregion
