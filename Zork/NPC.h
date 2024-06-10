#pragma once
#include "Creature.h"

class NPC : public Creature {
	NPC(std::string name, std::string description);
	~NPC();
};

