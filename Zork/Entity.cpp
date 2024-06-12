#include "Entity.h"

Entity::Entity(EntityType type) {
	this->type = type;
}

Entity::Entity(std::string name, std::string description, EntityType type) {
	this->name = name;
	this->description = description;
	this->type = type;
}

Entity::~Entity() {

}

void Entity::Update() {

}
