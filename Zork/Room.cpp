#include "Room.h"

Room::Room(std::string name, std::string description) : Entity(name, description, EntityType::ROOM) {
	
}

Room::~Room() {

}

void Room::Update() {

}

//Describe the room and the items we have in the room
void Room::Description() {
	std::cout << name << std::endl;
	std::cout << description << std::endl;
	for (Entity* entity : contains) {
		if (entity->type == EntityType::ITEM) {
			std::cout << "There is a " << entity->name << " here" << std::endl;
		}
	}
}
