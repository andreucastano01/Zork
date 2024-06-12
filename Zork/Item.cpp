#include "Item.h"

Item::Item(std::string name, std::string description, Room* loc) : Entity(name, description, EntityType::ITEM) {
	location = loc;
}

Item::~Item() {

}

void Item::Update() {

}
