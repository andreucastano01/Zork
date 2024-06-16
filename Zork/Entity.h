#pragma once
#include <string>
#include <list>

enum class EntityType {
	CREATURE,
	ITEM,
	ROOM,
	EXIT
};

class Entity {
public:
	EntityType type;
	std::string name;
	std::string description;
	std::list<Entity*> contains; //If we need entities inside other entities

	Entity(EntityType type);
	Entity(std::string name, EntityType type);
	Entity(std::string name, std::string description, EntityType type);
	~Entity();

	virtual void Update();
};