#pragma once

#include <vector>
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

	World();
	~World();

	void createEntities();
};