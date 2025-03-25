#include "GameManager.h"

int GameManager::GetAIMove()
{
    //not the best random option, for further projects look for other libraries
    int aiMove = std::rand() % 3;
    return aiMove;
}

GameManager::GameManager(InputManager* im, PrintManager* pm) :
    m_inputManager(im), m_printManager(pm), isGameRunning(false),
    scorePlayer(0), scoreAI(0), possiblePlays({ "Rock", "Paper", "Scisssors" })
{}

GameManager::Result GameManager::GetMatchResult(int playerMove, int aiMove)
{
    m_printManager->PrintMatchMoves(possiblePlays[playerMove], possiblePlays[aiMove]);

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

bool GameManager::CanInitGame()
{
    isGameRunning = m_inputManager->GetPlayerInput(2) == 1;
    return isGameRunning;
}

void GameManager::RunMatch(int playerMove, int& scorePlayer, int& scoreAI)
{
    int aiMove = GetAIMove();
    Result matchResult = GetMatchResult(playerMove, aiMove);

    if (matchResult == Result::Draw) {
        m_printManager->PrintDraw();
    }
    else {
        if (matchResult == Result::PlayerWon) {
            scorePlayer++;
            m_printManager->PrintPlayerWon();
        }

        if (matchResult == Result::AIWon) {
            scoreAI++;
            m_printManager->PrintAIWon();
        }
    }
}

void GameManager::Update()
{
    m_printManager->ClearScreen();

    m_printManager->PrintScore(scorePlayer, scoreAI);
    m_printManager->PrintMatchOptions();

    int option = m_inputManager->GetPlayerInput(3);

    if (option == 0)
    {
        m_printManager->ClearScreen();
        m_printManager->PrintMainMenu();

        if (CanInitGame()) {
            m_printManager->ClearScreen();
        }
    }
    else
    {
        RunMatch(option - 1, scorePlayer, scoreAI);

        system("PAUSE");
        m_printManager->ClearScreen();
    }
}

void GameManager::StartGame()
{
    m_printManager->PrintHeader();
    m_printManager->PrintMainMenu();
}
