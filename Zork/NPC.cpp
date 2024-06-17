#include "NPC.h"

NPC::NPC(std::string name, std::string description, Room* location, int life, int attack) : Creature(name, description, location, life, attack) {

}

NPC::~NPC() {
	conversation.clear();
}

void NPC::Update() {

}

//Adding dialogues to an npc
void NPC::Add(DialogueOptions option){
    conversation.push_back(option);
}

//Talk with an NPC
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
            //user input
            int choice;
            std::cin >> choice;
            //Clean buffer after reading input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        answer = false;
        currentOption = nextOption;
        nextOption = -99;
    }
}

//Damage by enemy
int NPC::Damage() {
    return attack;
}
