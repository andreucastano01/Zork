#pragma once
#include <string>
#include <vector>

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
	std::vector<Entity*> contains; //If we need entities inside other entities

	Entity(EntityType type);
	Entity(std::string name, std::string description, EntityType type);
	~Entity();

	virtual void Update();
};