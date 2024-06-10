#pragma once
#include "Creature.h"

class Player : public Creature {
	Player(std::string name, std::string description);
	~Player();
};

