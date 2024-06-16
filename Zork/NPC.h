#pragma once
#include <vector>
#include <sstream>
#include <algorithm>
#include "Creature.h"

struct DialogueOptions {
	int dialogueN;
	std::string sentence;
	std::vector<std::string> npcResponses;
	bool needAnswer = false;
	int nextDialogue = -99;
};

class NPC : public Creature {
public:
	std::vector<DialogueOptions> conversation;
	NPC(std::string name, std::string description, Room* location);
	~NPC();

	void Update() override;
	void Add(DialogueOptions option);
	void Talk(int currentOption = 1);
};
