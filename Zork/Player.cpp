#include "Player.h"

Player::Player(std::string name, std::string description, Room* location, int life, int attack) : Creature(name, description, location, life, attack) {
	hasLantern = false;
	itemEquipped = nullptr;
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
					if (FindObjectInventory(exit->key)) {
						std::cout << "You opened the door with a key" << std::endl;
						exit->closed = false;
					}
					else {
						if (exit->key->name.compare("notakey") == 0) return;
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
			if (itemEquipped == (Item*)entity) itemEquipped = nullptr;
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

void Player::Put(std::string itemInvent, std::string itemToPut) {
	if (itemInvent.compare(itemToPut) == 0) {
		std::cout << "You can't put an item inside the same item" << std::endl;
		return;
	}
	Item* item = nullptr;
	Item* item2 = nullptr;
	for (Entity* entity : contains) {
		if (entity->name.compare(itemInvent) == 0) item = (Item*)entity;
		if (entity->name.compare(itemToPut) == 0) item2 = (Item*)entity;
	}
	if (item != nullptr && item2 != nullptr) item->contains.push_back(item2);
}

//Search the inventory and see if we have the item
bool Player::FindObjectInventory(Item* itemToFind) {
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

//Equip an item
void Player::Equip(std::string item) {
	for (Entity* entity : contains) {
		if (entity->name.compare(item) == 0) {
			std::cout << "You equipped: " << entity->name << std::endl;
			Item* item = (Item*)entity;
			itemEquipped = item;
		}
	}
}

//Damage do it by the player
int Player::Damage() {
	if (itemEquipped != nullptr) {
		//std::cout << "My sword does: " << itemEquipped->damage << std::endl;
		return attack + itemEquipped->damage;
	}
	//std::cout << "I do: " << attack << std::endl;
	return attack;
}

//Automatic combat with an enemy
bool Player::Combat(NPC* enemy) {
	std::cout << "Your life: " << life << std::endl;
	std::cout << "Enemy life: " << enemy->life << std::endl;
	while (true) {
		enemy->life -= Damage();
		std::cout << "Enemy life: " << enemy->life << std::endl;
		if (enemy->life <= 0) {
			std::cout << "You defeated " << enemy->name << std::endl;
			return true;
		}
		life -= enemy->Damage();
		std::cout << "Your life: " << life << std::endl;
		if (life <= 0) return false;
	}
}