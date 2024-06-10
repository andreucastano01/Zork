#include "Creature.h"

Creature::Creature(std::string name, std::string description) : Entity(name, description)
{
	location = nullptr;
}

Creature::~Creature()
{
}
