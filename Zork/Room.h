#pragma once
#include "Entity.h"
#include <iostream>

class Room : public Entity
{
public:
	Room(std::string name, std::string description);
	~Room();

	void Update() override;

	void Description();
};

