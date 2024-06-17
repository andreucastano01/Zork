#pragma once
#include "Entity.h"
#include "Room.h"

class Item : public Entity {
public:
	int damage;

	Item(std::string name, std::string description, int damage);
	~Item();

	void Update() override;
};

