#pragma once
#include "Creature.h"

class NPC : public Creature {
public:
	NPC(std::string name, std::string description, Room* location);
	~NPC();

	void Update() override;
};

