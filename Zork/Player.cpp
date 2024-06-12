#include "Player.h"

Player::Player(std::string name, std::string description, Room* location) : Creature(name, description, location) {

}

Player::~Player() {

}

void Player::Move(Coordinates direction) {
	for (Entity* entity : location->contains) {
		if (entity->type == EntityType::EXIT) {
			Exit* exit = (Exit*)entity;
			if (exit->source == location && exit->direction == direction) {
				location = exit->destination;
			}
		}
	}
}