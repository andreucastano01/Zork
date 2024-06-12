#pragma once
#include "Entity.h"
#include "Room.h"

class Creature : public Entity {
public:
	Room* location;

	Creature(std::string name, std::string description, Room* loc);
	~Creature();

	void Update() override;
};