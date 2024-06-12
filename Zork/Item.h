#pragma once
#include "Entity.h"
#include "Room.h"

class Item : public Entity {
public:
	Room* location;

	Item(std::string name, std::string description, Room* loc);
	~Item();

	void Update() override;
};

