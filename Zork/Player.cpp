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
				return;
			}
		}
	}
}

void Player::GetItem(std::string item) {
	for (auto it = location->contains.begin(); it != location->contains.end(); ) {
		Entity* entity = *it;
		if (entity->type == EntityType::ITEM && item.compare(entity->name) == 0) {
			std::cout << "You taked the " << (*it)->name << std::endl;
			contains.push_back((Item*)entity);
			it = location->contains.erase(it);
			return;
		}
		else {
			it++;
		}
	}
	std::cout << "There's no " << item << " here" << std::endl;
}

void Player::DropItem(std::string item) {
	for (auto it = contains.begin(); it != contains.end(); ) {
		Entity* entity = *it;
		if (entity->type == EntityType::ITEM && item.compare(entity->name) == 0) {
			std::cout << "You dropped the " << (*it)->name << std::endl;
			location->contains.push_back((Item*)entity);
			it = contains.erase(it);
			return;
		}
		else {
			it++;
		}
	}
	std::cout << "You don't have the " << item << std::endl;
}

void Player::SeeInventory() {
	if (contains.empty()) std::cout << "The inventory is empty" << std::endl;
	else {
		for (Entity* entity : contains) {
			if (entity->type == EntityType::ITEM) {
				Item* item = (Item*)entity;
				std::cout << item->name << std::endl;
			}
		}
	}
}