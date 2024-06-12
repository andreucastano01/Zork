#pragma once
#include "Creature.h"
#include "Exit.h"
#include <iostream>

class Player : public Creature {
public:
	Player(std::string name, std::string description, Room* location);
	~Player();

	void Move(Coordinates direction);
};

