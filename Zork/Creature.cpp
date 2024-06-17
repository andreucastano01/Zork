#include "Creature.h"

Creature::Creature(std::string name, std::string description, Room* loc, int life, int attack) : Entity(name, description, EntityType::CREATURE) {
	location = loc;
	this->life = life;
	this->attack = attack;
}

Creature::~Creature() {

}

void Creature::Update() {

}

int Creature::Damage() {
	return attack;
}