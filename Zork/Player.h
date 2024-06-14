#pragma once

#include <iostream>
#include "Creature.h"
#include "Exit.h"
#include "Item.h"

class Player : public Creature {
public:
	bool hasLantern;

	Player(std::string name, std::string description, Room* location);
	~Player();

	void Update() override;

	void Move(Coordinates direction);
	void GetItem(std::string item);
	void DropItem(std::string item);
	void SeeInventory();
	bool findObjectInventory(Item* itemToFind);
};

