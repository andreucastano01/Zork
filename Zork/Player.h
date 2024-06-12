#pragma once
#include "Creature.h"

class Player : public Creature {
public:
	Player(std::string name, std::string description, Room* location);
	~Player();
};

