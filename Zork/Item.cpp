#include "Item.h"

Item::Item(std::string name, std::string description, int damage) : Entity(name, description, EntityType::ITEM) {
	this->damage = damage;
}

Item::~Item() {

}

void Item::Update() {

}
