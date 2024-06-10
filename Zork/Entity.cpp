#include "Entity.h"

Entity::Entity(std::string name, std::string description)
{
	this->name = name;
	this->description = description;
	type = EntityType::ROOM;
}

Entity::~Entity()
{
}
