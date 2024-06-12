// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include "World.h"

int main() {
    World world;
    world.createEntities();

    std::cout << "Put help for getting info about the commands!" << std::endl;
    std::cout << "Welcome to Zork!" << std::endl;

    world.Play();
}