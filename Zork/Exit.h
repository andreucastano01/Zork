#pragma once
#include "Entity.h"
#include "Room.h"

enum class Coordinates {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Exit : public Entity {
public: 
	Coordinates direction;
	Room* source;
	Room* destination;

	Exit(Coordinates direction, Room* src, Room* dst);
	~Exit();

	void Update() override;
};