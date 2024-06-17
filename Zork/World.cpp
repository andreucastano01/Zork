#include "World.h"

World::World() {
	player = nullptr;
	isFinished = false;
	commandUnlocked = false;
	firstTimeFirstFloor = false;
}

World::~World() {
	//We need to delete all the entities before cleaning
	for (Entity* entity : entities) {
		delete entity;
	}

	entities.clear();
}

void World::createEntities() {
	//Rooms
	Room* room1 = new Room("Cell", "A small, dimly lit cell with cold, stone walls. The air is damp and carries the faint scent of mold. In the floor you can see a bored person.");
	Room* room2 = new Room("Basement", "The basement of the prison, a dark and foreboding place with a low ceiling and the echo of distant drips of water.");
	Room* room3 = new Room("Hallway", "A hallway stretches out, lined with more cells. The oppressive silence is broken only by the occasional distant clang.");
	Room* room4 = new Room("First floor", "The first floor of the prison, where a slight draft hints at the world beyond these walls.");
	Room* room5 = new Room("Cell 2", "Another cell, nearly identical to the previous one. The walls are equally grim and uninviting.");
	Room* room6 = new Room("Cell 3", "Yet another cell, this one feels slightly more claustrophobic, with walls that seem to close in.");
	Room* room7 = new Room("Guard's office", "The guard's office, a stark contrast to the rest of the prison with its slightly warmer atmosphere and faint light filtering through a barred window.");
	Room* room8 = new Room("Store", "The store, a small room that feels almost out of place in the prison, with relatively cleaner walls and a sense of quiet purpose.");

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
	Exit* exit12 = new Exit("exit12", Coordinates::NORTH, room1, room2, true);
	Exit* exit21 = new Exit("exit21", Coordinates::SOUTH, room2, room1, true);

	//Basement - Hallway
	Exit* exit23 = new Exit("exit23", Coordinates::WEST, room2, room3, false);
	Exit* exit32 = new Exit("exit32", Coordinates::EAST, room3, room2, false);

	//Basement - First floor
	Exit* exit24 = new Exit("exit24", Coordinates::NORTH, room2, room4, false);
	Exit* exit42 = new Exit("exit42", Coordinates::NORTH, room4, room2, false);

	//Cell 1 - Guard's office
	Exit* exit17 = new Exit("exit17", Coordinates::SOUTH, room1, room7, true);
	Exit* exit71 = new Exit("exit71", Coordinates::WEST, room7, room1, false);

	//Basement - Store
	Exit* exit28 = new Exit("exit28", Coordinates::EAST, room2, room8, false);
	Exit* exit82 = new Exit("exit82", Coordinates::WEST, room8, room2, false);

	//Hallway - Guard's office
	Exit* exit37 = new Exit("exit37", Coordinates::WEST, room3, room7, true);
	Exit* exit73 = new Exit("exit73", Coordinates::EAST, room7, room3, true);

	//Hallway - Cell 2
	Exit* exit35 = new Exit("exit35", Coordinates::NORTH, room3, room5, false);
	Exit* exit53 = new Exit("exit53", Coordinates::SOUTH, room5, room3, false);

	//Hallway - Cell 3
	Exit* exit36 = new Exit("exit36", Coordinates::SOUTH, room3, room6, false);
	Exit* exit63 = new Exit("exit63", Coordinates::NORTH, room6, room3, false);

	//Exit Win = new Exit(Coordinates::SOUTH, room4, ?);

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
	//Item* toilet = new Item("toilet", "A toilet you need to move", room1);
	Item* lantern = new Item("lantern", "Is a good idea to have light", 1);
	Item* key = new Item("key", "A key for open a door", 1);
	Item* sword = new Item("sword", "A sword for fighting", 15);
	Item* notakey = new Item("notakey", "notakey", 1);
	Item* notakey2 = new Item("notakey2", "notakey2", 1);

	//entities.push_back(toilet);
	entities.push_back(lantern);
	entities.push_back(key);
	entities.push_back(sword);
	entities.push_back(notakey);
	entities.push_back(notakey2);

	//Creatures
	player = new Player("Player", "The player", room1, 50, 10);

	DialogueOptions option1 = { 1, "Jajajajaja, it seems I have a new cellmate. My name is Jan. What is your name?", {}, true, 2 };
	DialogueOptions option2 = { 2, "Nice to meet you. Can you help me scratch my back ? Since I lost my hands, it is an impossible task for me.", {} };
	DialogueOptions option3 = { 3, "Oh, thank you. Now I feel much better. I'm going to tell you a secret. Behind the toilet there is a sewer that will help you escape. But be careful, if they catch you, you will be left without hands.", {} };

	NPC* cellmate = new NPC("cellmate", "A cellmate", room1, 1, 1);
	cellmate->Add(option1);
	cellmate->Add(option2);
	cellmate->Add(option3);

	NPC* guard = new NPC("guard", "A guard", room4, 100, 15);

	entities.push_back(player);
	entities.push_back(cellmate);
	entities.push_back(guard);

	//Rooms contains exits
	room1->contains.push_back(exit12);
	room1->contains.push_back(exit17);
	room2->contains.push_back(exit21);
	room2->contains.push_back(exit23);
	room2->contains.push_back(exit24);
	room2->contains.push_back(exit28);
	room3->contains.push_back(exit32);
	room3->contains.push_back(exit35);
	room3->contains.push_back(exit36);
	room3->contains.push_back(exit37);
	room4->contains.push_back(exit42);
	room5->contains.push_back(exit53);
	room6->contains.push_back(exit63);
	room7->contains.push_back(exit71);
	room7->contains.push_back(exit73);
	room8->contains.push_back(exit82);

	//Room contains items
	//room1->contains.push_back(toilet);
	room1->contains.push_back(lantern);
	room7->contains.push_back(key);
	room8->contains.push_back(sword);

	//Some exits needs keys
	exit12->addKey(key);
	exit21->addKey(key);
	exit17->addKey(notakey);
	exit37->addKey(notakey2);
	exit73->addKey(notakey2);
}

void World::Play() {
	std::cout << "I just woke up from a long sleep. I feel disoriented and astonished. I look around and see nothing. On one side on the floor of the room, there is a lantern." << std::endl;
	std::cout << std::endl;

	while (!isFinished) {
		readInput();
		std::cout << std::endl;

		if (player->location->name.compare("First floor") == 0 && !firstTimeFirstFloor) {
			std::cout << "A guard attacked you from behind" << std::endl;
			for (Entity* entity : entities) {
				if (entity->name.compare("guard") == 0) {
					NPC* guard = (NPC*)entity;
					firstTimeFirstFloor = true;
					if (!player->Combat(guard)) {
						std::cout << "You lost. Try getting a sword next time and equip it." << std::endl;
						isFinished = true;
					}
				}
			}
		}
	}
}

//User input and commands
void World::readInput() {
	//Read input from user
	std::string input;
	std::getline(std::cin, input);

	std::vector<std::string> words;
	std::istringstream iss(input);
	std::string word;
	while (iss >> word) {
		std::transform(word.begin(), word.end(), word.begin(), ::tolower); //Passing all to lower so I dont have problems with words
		words.push_back(word);
	}

	//We need a lantern to do things
	if (!player->hasLantern) {
		if (words.size() == 2 && (words[0].compare("take") == 0 || words[0].compare("get") == 0 || words[0].compare("grab") == 0) && words[1].compare("lantern") == 0) {
			player->GetItem(words[1]);
			player->hasLantern = true;
			player->location->Description();
		}
		else if (words.size() == 1 && words[0].compare("exit") == 0) {
			isFinished = true;
		}
		else if (words.size() == 1 && words[0].compare("help") == 0) {
			helpCommands();
		}
		else {
			std::cout << "It's too dark to do and see anything without a lantern." << std::endl;
			std::cout << std::endl;
		}
		return;
	}

	//We separate the commands for words in the input
	//0 words = no input
	if (words.size() == 0) {
		std::cout << "No command provided." << std::endl;
		readInput();
		return;
	}

	//1 word
	else if (words.size() == 1) {
		//Movement commands
		if (words[0].compare("north") == 0) {
			player->Move(Coordinates::NORTH);
		}
		else if (words[0].compare("east") == 0) {
			player->Move(Coordinates::EAST);
		}
		else if (words[0].compare("west") == 0) {
			player->Move(Coordinates::WEST);
		}
		else if (words[0].compare("south") == 0) {
			if (player->location->name.compare("First floor") == 0) {
				std::cout << "You escaped the prison!" << std::endl;
				isFinished = true;
			}
			player->Move(Coordinates::SOUTH);
		}

		//Inventory
		else if (words[0].compare("inventory") == 0) {
			player->SeeInventory();
		}

		//Brief description of the place
		else if (words[0].compare("description") == 0 || words[0].compare("look") == 0) {
			player->location->Description();
		}

		//Exit command
		else if (words[0].compare("exit") == 0) {
			isFinished = true;
		}

		//Help command
		else if (words[0].compare("help") == 0) {
			helpCommands();
		}

		else {
			std::cout << "I can't understand you, please repeat the accion" << std::endl;
			readInput();
		}
	}

	//2 words
	else if (words.size() == 2) {
		//Movement commands
		if (words[0].compare("move") == 0) {
			if (words[1].compare("north") == 0) {
				player->Move(Coordinates::NORTH);
			}
			else if (words[1].compare("east") == 0) {
				player->Move(Coordinates::EAST);
			}
			else if (words[1].compare("west") == 0) {
				player->Move(Coordinates::WEST);
			}
			else if (words[1].compare("south") == 0) {
				if (player->location->name.compare("First floor") == 0) {
					std::cout << "You escaped the prison!" << std::endl;
					isFinished = true;
				}
				player->Move(Coordinates::SOUTH);
			}
		}

		//Get an item
		else if (words[0].compare("take") == 0 || words[0].compare("get") == 0 || words[0].compare("grab") == 0 || words[0].compare("pick") == 0) {
			player->GetItem(words[1]);
		}

		//Drop an item
		else if (words[0].compare("drop") == 0) {
			player->DropItem(words[1]);
			if (words[1].compare("lantern") == 0) player->hasLantern = false;
		}

		//Equip an item (You don't need to unequip items)
		else if (words[0].compare("equip") == 0) {
			player->Equip(words[1]);
		}

		//Scratch cellmate
		else if (words[0].compare("scratch") == 0 && commandUnlocked) {
			bool exitUnlocked = false;
			for (Entity* entity : entities) {
				if (words[1].compare(entity->name) == 0) {
					NPC* cellmate = (NPC*)entity;
					cellmate->Talk(3);
					exitUnlocked = true;
				}
			}
			if (exitUnlocked) {			
				for (Entity* entity : entities) {
					if (entity->name.compare("exit17") == 0) {	
						Exit* exit = (Exit*)entity;
						exit->closed = false;
					}	
				}
			}
		}

		//Talk with an NPC
		else if (words[0].compare("talk") == 0) {
			for (Entity* entity : entities) {
				if (words[1].compare(entity->name) == 0) {
					NPC* npc = (NPC*)entity;
					npc->Talk();
					if (words[1].compare("cellmate") == 0) commandUnlocked = true;
				}
			}
		}

		else {
			std::cout << "I can't understand you, please repeat the accion" << std::endl;
			readInput();
		}
	}

	/*
	else if (words.size() == 3) {
		//Join two items (it has to make sense)
		else if (words[0].compare("put") == 0) {
			player->Put(words[1], words[2]);
		}

		else {
			std::cout << "I can't understand you, please repeat the accion" << std::endl;
			readInput();
		}
	}
	*/

	else {
		std::cout << "I can't understand you, please repeat the accion" << std::endl;
		readInput();
	}
}

//function with the commands info
void World::helpCommands() {
	std::cout << "Available commands:" << std::endl;
	std::cout << "  - 'north': Move the player to the north." << std::endl;
	std::cout << "  - 'east': Move the player to the east." << std::endl;
	std::cout << "  - 'west': Move the player to the west." << std::endl;
	std::cout << "  - 'south': Move the player to the south." << std::endl;
	std::cout << "  - 'move direction': Move the player to a direction." << std::endl;
	std::cout << "  - 'take/get/grab/pick item': Grab an item and put it on your inventory." << std::endl;
	std::cout << "  - 'inventory': See the inventory." << std::endl;
	std::cout << "  - 'look/description': Briefly explain the room." << std::endl;
	std::cout << "  - 'talk person': Talk with a person." << std::endl;
	std::cout << "  - 'equip item': Equip an item." << std::endl;
	std::cout << "  - 'exit': Exit the game." << std::endl;
	std::cout << "  - 'help': For showing this help message." << std::endl;
}
