#pragma once
#include "Entity.h"
#include "Room.h"
#include "Item.h"

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
	bool closed;
	Item* key;

	Exit(Coordinates direction, Room* src, Room* dst, bool clsed);
	~Exit();

	void Update() override;

	void addKey(Item* key);
};