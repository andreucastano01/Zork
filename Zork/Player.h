#pragma once

#include <iostream>
#include "Creature.h"
#include "Exit.h"
#include "Item.h"
#include "NPC.h"

class Player : public Creature {
public:
	bool hasLantern;
	Item* itemEquipped;

	Player(std::string name, std::string description, Room* location, int life, int attack);
	~Player();

	void Update() override;

	void Move(Coordinates direction);
	void GetItem(std::string item);
	void DropItem(std::string item);
	void SeeInventory();
	void Put(std::string itemInvent, std::string itemToPut);
	bool FindObjectInventory(Item* itemToFind);
	bool Combat(NPC* enemy);
	void Equip(std::string item);
	int Damage() override;
};

