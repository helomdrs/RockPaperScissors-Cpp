#pragma once

#include "InputManager.h"
#include "PrintManager.h"

struct GameManager
{
    std::vector<std::string> possiblePlays;
    InputManager* m_inputManager;
    PrintManager* m_printManager;

    bool isGameRunning;
    int scorePlayer;
    int scoreAI;

    GameManager(InputManager* im, PrintManager* pm):
        m_inputManager(im), m_printManager(pm), isGameRunning(false), 
        scorePlayer(0), scoreAI(0), possiblePlays({"Rock", "Paper", "Scisssors"}) { }
    
    //using ENUM because it makes more sense for the code than structs
    enum Result
    {
        Draw,
        PlayerWon,
        AIWon
    };

    static int getAIMove() {
        //not the best random option, for further projects look for other libraries
        int aiMove = std::rand() % 3;
        return aiMove;
    }

    //a copy of a variable costs less memory than a pointer, prefer to use pointers on Objects references
    //if a variable will be modified, use reference (&) instead
    Result getMatchResult(int playerMove, int aiMove)
    {
        m_printManager->printMatchMoves(possiblePlays[playerMove], possiblePlays[aiMove]);

        if (playerMove == aiMove) return Result::Draw;

        if (playerMove == 0) {
            return aiMove == 2 ? Result::PlayerWon : Result::AIWon;
        }

        if (playerMove == 1) {
            return aiMove == 0 ? Result::PlayerWon : Result::AIWon;
        }

        if (playerMove == 2) {
            return aiMove == 1 ? Result::PlayerWon : Result::AIWon;
        }
    }

    bool canInitGame() {
        const bool toInitGame = m_inputManager->getPlayerInput(2) == 1;
        return toInitGame;
    }

    void runMatch(int playerMove, int& scorePlayer, int& scoreAI)
    {
        int aiMove = getAIMove();
        Result matchResult = getMatchResult(playerMove, aiMove);

        if (matchResult == Result::Draw) {
            m_printManager->printDraw();
        }
        else {
            if (matchResult == Result::PlayerWon) {
                scorePlayer++;
                m_printManager->printPlayerWon();
            }

            if (matchResult == Result::AIWon) {
                scoreAI++;
                m_printManager->printAIWon();
            }
        }
    }
};