#pragma once
#include "Entity.h"
#include "Room.h"

class Item : public Entity {
public:
	Item(std::string name, std::string description);
	~Item();

	void Update() override;
};

