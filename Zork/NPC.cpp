#include "NPC.h"

NPC::NPC(std::string name, std::string description, Room* location) : Creature(name, description, location) {

}

NPC::~NPC() {
	conversation.clear();
}

void NPC::Update() {

}

void NPC::Add(DialogueOptions option){
    conversation.push_back(option);
}

void NPC::Talk(int currentOption) {
    bool answer = false;
    int nextOption = -99;
    while (currentOption != -99) {
        for (DialogueOptions dialogue : conversation) {
            if (dialogue.dialogueN == currentOption) {
                std::cout << dialogue.sentence << std::endl;
                for (std::string answers : dialogue.npcResponses) {
                    std::cout << answers << std::endl;
                }
                answer = dialogue.needAnswer;
                nextOption = dialogue.nextDialogue;
            }
        }
        if (answer) {
            int choice;
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        answer = false;
        currentOption = nextOption;
        nextOption = -99;
    }
}
