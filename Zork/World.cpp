#include "World.h"

World::World() {
	player = nullptr;
}

World::~World() {

}

void World::createEntities() {
	//Rooms
	Room* room1 = new Room("Cell", "You seem to be on a cell. If you look around you can see a toilet, a bed, an a cellmate.");
	Room* room2 = new Room("Basement", "The basement of the prison");
	Room* room3 = new Room("Hallway", "The hallway. You can see more cells and a closed door.");
	Room* room4 = new Room("First floor", "The first floor of the prison before the exit");
	Room* room5 = new Room("Cell 2", "Another cell");
	Room* room6 = new Room("Cell 3", "Another cell");
	Room* room7 = new Room("Guard's office", "The guard's office");
	Room* room8 = new Room("Store", "You can see a sword");

	entities.push_back(room1);
	entities.push_back(room2);
	entities.push_back(room3);
	entities.push_back(room4);
	entities.push_back(room5);
	entities.push_back(room6);
	entities.push_back(room7);
	entities.push_back(room8);

	//Exits
	//You can go and come back
	//Cell 1 - Basement
	Exit* exit12 = new Exit(Coordinates::NORTH, room1, room2);
	Exit* exit21 = new Exit(Coordinates::SOUTH, room2, room1);

	//Basement - Hallway
	Exit* exit23 = new Exit(Coordinates::WEST, room2, room3);
	Exit* exit32 = new Exit(Coordinates::EAST, room3, room2);

	//Basement - First floor
	Exit* exit24 = new Exit(Coordinates::NORTH, room2, room4);
	Exit* exit42 = new Exit(Coordinates::NORTH, room4, room2);

	//Cell 1 - Guard's office
	Exit* exit17 = new Exit(Coordinates::SOUTH, room1, room7);
	Exit* exit71 = new Exit(Coordinates::WEST, room7, room1);

	//Basement - Store
	Exit* exit28 = new Exit(Coordinates::EAST, room2, room8);
	Exit* exit82 = new Exit(Coordinates::WEST, room8, room2);

	//Hallway - Guard's office
	Exit* exit37 = new Exit(Coordinates::WEST, room3, room7);
	Exit* exit73 = new Exit(Coordinates::EAST, room7, room3);

	//Hallway - Cell 2
	Exit* exit35 = new Exit(Coordinates::NORTH, room3, room5);
	Exit* exit53 = new Exit(Coordinates::SOUTH, room5, room3);

	//Hallway - Cell 3
	Exit* exit36 = new Exit(Coordinates::SOUTH, room3, room6);
	Exit* exit63 = new Exit(Coordinates::NORTH, room6, room3);

	//Exit Win = new Exit(Coordinates::SOUTH, (Room*)room4, ?);

	entities.push_back(exit12);
	entities.push_back(exit21);
	entities.push_back(exit23);
	entities.push_back(exit32);
	entities.push_back(exit24);
	entities.push_back(exit42);
	entities.push_back(exit17);
	entities.push_back(exit71);
	entities.push_back(exit28);
	entities.push_back(exit82);
	entities.push_back(exit37);
	entities.push_back(exit73);
	entities.push_back(exit35);
	entities.push_back(exit53);
	entities.push_back(exit36);
	entities.push_back(exit63);

	//Items
	Item* toilet = new Item("Toilet", "A toilet you need to move", room1);
	Item* key = new Item("Key", "A key for open a door", room7);
	Item* lantern = new Item("Lantern", "Is a good idea to have light", room1);

	entities.push_back(key);
	entities.push_back(lantern);

	//Creatures
	player = new Player("Player", "The player", room1);
	NPC* cellmate = new NPC("cellmate", "NPC1", room1);

	entities.push_back(player);
	entities.push_back(cellmate);
}
