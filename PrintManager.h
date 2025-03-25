#pragma once

#include <iostream>
#include <string>
#include <vector>

struct PrintManager 
{
    //Private
    std::vector<std::string> availableStrings = {
    "#",
    "ROCK, PAPER, SCISSORS",
    "C++ entry project",
    "Main Menu\n    1. Play\n    2. Exit\nChoose an option: ",
    "Choose your move: \n    1. Rock \n    2. Paper \n    3. Scissors \n    0. Exit Game \nYour move: ",
    "PLAYER %i x %i AI\n",
    "Oh, it's a draw...",
    "Player wins!",
    "AI wins!",
    "Invalid input, please type only numbers and choose a valid option above: ",
    "\nPLAYER - %s x %s - AI\n\n"
    };

    void PrintHashLine(const int& charPerLine, std::string& finalString);
    void PrintBlankLine(const int& charPerLine, std::string& finalString);
    void PrintTitle(const int& charPerLine, std::string& finalString, int titleLevel);

    void SimplePrint(int index, bool endl);

    //Public
    void PrintHeader();
    void PrintScore(int& scorePlayer, int& scoreAI);
    void PrintMainMenu();
    void PrintMatchOptions();
    void PrintMatchMoves(std::string playerMove, std::string aiMove);
    void PrintDraw();
    void PrintPlayerWon();
    void PrintAIWon();
    void ClearScreen();
};