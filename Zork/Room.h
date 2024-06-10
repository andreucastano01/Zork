#pragma once
#include "Entity.h"

class Room : public Entity
{
	Room(std::string name, std::string description);
	~Room();
};

