#pragma once
#include "Entity.h"

class Item : public Entity {
	Item(std::string name, std::string description);
	~Item();
};

