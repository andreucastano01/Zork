#include "Exit.h"

Exit::Exit(std::string name, std::string description, Coordinates direction) : Entity(name, description)
{
	this->direction = direction;
	source = nullptr;
	destination = nullptr;
}

Exit::~Exit() {

}
