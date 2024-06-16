#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"
#include "Player.h"
#include "NPC.h"


class World {
public:
	std::vector<Entity*> entities;
	Player* player;
	bool isFinished;
	bool commandUnlocked;

	World();
	~World();

	void createEntities();
	void Play();
	void readInput();
	void helpCommands();
};