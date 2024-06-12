#include "Exit.h"

Exit::Exit(Coordinates direction, Room* src, Room* dst) 
	: Entity(EntityType::EXIT) {
	this->direction = direction;
	source = src;
	destination = dst;
}

Exit::~Exit() {

}

void Exit::Update() {

}
