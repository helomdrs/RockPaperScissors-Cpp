#pragma once

#include <iostream>
#include <string>
#include <vector>

struct PrintManager 
{
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

    void printHashLine(const int& charPerLine, std::string& finalString)
    {
        for (int i = 1; i < charPerLine; i++)
        {
            finalString.append(availableStrings[0]);
        };

        finalString.append("\n");
    }

    void printBlankLine(const int& charPerLine, std::string& finalString)
    {
        for (int i = 1; i < charPerLine; i++)
        {
            if (i <= 2 || i >= 58) {
                finalString.append(availableStrings[0]);
            }
            else {
                finalString.append(" ");
            }
        }

        finalString.append("\n");
    }

    void printTitle(const int& charPerLine, std::string& finalString, int titleLevel)
    {
        for (int i = 1; i <= charPerLine; i++)
        {
            if (i <= 2 || i >= 59) {
                finalString.append(availableStrings[0]);
            }
            else if (i == std::round((30 - availableStrings[titleLevel].length() / 2)))
            {
                finalString.append(availableStrings[titleLevel]);
                i += availableStrings[titleLevel].length();
            }
            else {
                finalString.append(" ");
            }
        }

        finalString.append("\n");
    }

    void printHeader()
    {
        std::string toPrint = "";
        const int charPerLine = 60;

        printHashLine(charPerLine, toPrint);
        printBlankLine(charPerLine, toPrint);
        printTitle(charPerLine, toPrint, 1);
        printTitle(charPerLine, toPrint, 2);
        printBlankLine(charPerLine, toPrint);
        printHashLine(charPerLine, toPrint);

        std::cout << toPrint << std::endl;
    }

    void printScore(int& scorePlayer, int& scoreAI)
    {
        std::printf(availableStrings[5].c_str(), scorePlayer, scoreAI);
    }

    void printMainMenu()
    {
        simplePrint(3, false);
    }

    void printMatchOptions()
    {
        simplePrint(4, false);
    }

    void printMatchMoves(std::string playerMove, std::string aiMove)
    {
        std::printf(availableStrings[10].c_str(), playerMove.c_str(), aiMove.c_str());
    }

    void printDraw()
    {
        simplePrint(6, true);
    }

    void printPlayerWon()
    {
        simplePrint(7, true);
    }

    void printAIWon()
    {
        simplePrint(8, true);
    }

    void simplePrint(int index, bool endl) 
    {
        if(endl)
            std::cout << availableStrings[index] << std::endl;
        else
            std::cout << availableStrings[index];
    }

    void clearScreen()
    {
        system("cls");
        printHeader();
    }
};