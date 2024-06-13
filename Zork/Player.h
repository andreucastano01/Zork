#pragma once

#include <iostream>
#include "Creature.h"
#include "Exit.h"
#include "Item.h"

class Player : public Creature {
public:
	Player(std::string name, std::string description, Room* location);
	~Player();

	void Move(Coordinates direction);
	void GetItem(std::string item);
	void DropItem(std::string item);
	void SeeInventory();
};

