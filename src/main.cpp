#include <iostream>
#include "gui/boardgui.h"

int main(int argc, char** argv)
{

    int population;
    int timestep;

    std::string population_input;
    std::string timestep_input;

    std::cout << "Hello and welcome to Conway's Game of Life!" << std::endl << std::endl;

    std::cout << "The game stops when all the cells die. You can reset the game by clicking the window." <<std::endl;

    std::cout << "You can force a reset of the game by clicking the window 3 times with the Left Button. Clicking with the Right Button resets the clicks counter." << std::endl << std::endl;

    std::cout << "Please enter population number (default 20)" << std::endl;

    std::getline(std::cin, population_input);

    try {
        population = stoi(population_input);
    } catch (const std::exception &e) {
        population = 20;
    }

    std::cout << "Please enter window's refresh timestep (default 500ms)" <<std::endl;
    
    std::getline(std::cin, timestep_input);

    try {
        timestep = stoi(timestep_input);
    } catch (const std::exception &e) {
        timestep = 500;
    }

    initGame(argc, argv, population, timestep);
    return 0;
}

