#include "Player.h"

Player::Player(std::string name, std::string description, Room* location) : Creature(name, description, location) {
	hasLantern = false;
}

Player::~Player() {

}

void Player::Update() {

}

//Moving character
void Player::Move(Coordinates direction) {
	for (Entity* entity : location->contains) {
		if (entity->type == EntityType::EXIT) {
			Exit* exit = (Exit*)entity;
			if (exit->source == location && exit->direction == direction) {
				//We need to check if the door is closed and if it is closed, if we have the key
				if (exit->closed) {
					if (findObjectInventory(exit->key)) {
						std::cout << "You opened the door with a key" << std::endl;
						exit->closed = false;
					}
					else {
						std::cout << "The door is closed, try to find a key." << std::endl;
						return;
					}
				}
				//We can move to the next room
				location = exit->destination;
				location->Description();
				return;
			}
		}
	}
}

void Player::GetItem(std::string item) {
	//See items in the room
	for (auto it = location->contains.begin(); it != location->contains.end(); ) {
		Entity* entity = *it;
		if (entity->type == EntityType::ITEM && item.compare(entity->name) == 0) {
			//If we find the item we put it on the inventory
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
	//See items in the inventory
	for (auto it = contains.begin(); it != contains.end(); ) {
		Entity* entity = *it;
		if (entity->type == EntityType::ITEM && item.compare(entity->name) == 0) {
			//We drop the item on the room
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

//Print items from inventory
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

//Search the inventory and see if we have the item
bool Player::findObjectInventory(Item* itemToFind) {
	if (contains.empty()) return false;
	else {
		for (Entity* entity : contains) {
			if (entity->type == EntityType::ITEM) {
				Item* item = (Item*)entity;
				if (item->name.compare(itemToFind->name) == 0) return true;
			}
		}
	}
	return false;
}