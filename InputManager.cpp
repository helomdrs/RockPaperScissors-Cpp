#include "InputManager.h"

int InputManager::GetPlayerInput(int lastOptionAvailable)
{
    int input = 0;
    std::cin >> input;

    while (std::cin.fail() || (input > lastOptionAvailable || input < 0))
    {
        std::cout << "Invalid input, please type only numbers and choose a valid option above: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> input;
    }

    return input;
}
