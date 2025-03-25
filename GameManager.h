#pragma once

#include "InputManager.h"
#include "PrintManager.h"

struct GameManager
{
    //Private
    std::vector<std::string> possiblePlays;
    InputManager* m_inputManager;
    PrintManager* m_printManager;

    int scorePlayer;
    int scoreAI;

    //using ENUM because it makes more sense for the code than structs
    enum Result
    {
        Draw,
        PlayerWon,
        AIWon
    };

    static int GetAIMove();
    GameManager(InputManager* im, PrintManager* pm);

    //Public

    bool isGameRunning;
    
    //a copy of a variable costs less memory than a pointer, prefer to use pointers on Objects references
    //if a variable will be modified, use reference (&) instead
    Result GetMatchResult(int playerMove, int aiMove);

    bool CanInitGame();
    void RunMatch(int playerMove, int& scorePlayer, int& scoreAI);
    void Update();
    void StartGame();
};