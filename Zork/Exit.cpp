#include "Exit.h"

Exit::Exit(Coordinates direction, Room* src, Room* dst, bool clsed) 
	: Entity(EntityType::EXIT) {
	this->direction = direction;
	source = src;
	destination = dst;
	closed = clsed;
	key = nullptr;
}

Exit::~Exit() {

}

void Exit::Update() {

}

void Exit::addKey(Item* key) {
	this->key = key;
}
