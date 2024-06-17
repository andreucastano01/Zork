#pragma once
#include "Entity.h"
#include "Room.h"

class Creature : public Entity {
public:
	Room* location;
	int life;
	int attack;

	Creature(std::string name, std::string description, Room* loc, int life, int attack);
	~Creature();

	void Update() override;
	virtual int Damage();
};