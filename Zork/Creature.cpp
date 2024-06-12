#include "Creature.h"

Creature::Creature(std::string name, std::string description, Room* loc) : Entity(name, description, EntityType::CREATURE) {
	location = loc;
}

Creature::~Creature() {

}

void Creature::Update() {

}
