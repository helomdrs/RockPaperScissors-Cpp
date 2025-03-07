#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> possiblePlays{ "Rock", "Paper", "Scissors" };

#pragma region Print Methods

static void printHeader()
{
    std::cout << "#############################################################" << std::endl;
    std::cout << "##                                                         ##" << std::endl;
    std::cout << "##               ROCK, PAPER, SCISSORS                     ##" << std::endl;
    std::cout << "##                 C++ entry project                       ##" << std::endl;
    std::cout << "##                                                         ##" << std::endl;
    std::cout << "#############################################################" << std::endl;
    std::cout << "\n";
}

static void printScore(int* scorePlayer, int* scoreAI)
{
    std::cout << "                   PLAYER " << *scorePlayer << " x " << *scoreAI << " AI" <<  std::endl;
}

static void printMainMenu() 
{
    std::cout << "Main Menu " << std::endl;
    std::cout << "  1. Play" << std::endl;
    std::cout << "  2. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

static void printMatchOptions()
{
    std::cout << "Choose an option: " << std::endl;
    std::cout << "  1. Rock" << std::endl;
    std::cout << "  2. Paper" << std::endl;
    std::cout << "  3. Scissors" << std::endl;
    std::cout << "  0. Exit Game" << std::endl;
    std::cout << "Your move: ";
}

static void clearScreen()
{
    system("cls");
    printHeader();
}
#pragma endregion

static int getPlayerInput(int maxAmount)
{
    int input = 0;
    std::cin >> input;

    while (std::cin.fail() || (input > maxAmount || input < 0))
    {
        std::cout << "Invalid input, please type only numbers or choose a valid option above: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> input;
    }

    return input;
}

static bool canInitGame()
{
    bool toInitGame = false;

    int option = getPlayerInput(2);

    switch (option)
    {
    case 1:
        toInitGame = true;
        break;
    case 2:
        toInitGame = false;
        break;
    default:
        toInitGame = false;
        break;
    }

    return toInitGame;
}

#pragma region Match Methods

static int getAIMove() 
{
    int aiMove = std::rand() % 4;

    if (aiMove > possiblePlays.size())
    {
        aiMove = std::rand() % 3;
    }
    
    return aiMove;
}

static int treatMoves(int* playerMove, int* aiMove) 
{
    //std::cout << "Player move: " << possiblePlays[*playerMove - 1] << std::endl;
    //std::cout << "AI move: " << possiblePlays[*aiMove - 1] << std::endl;

    int idxPlayerMove = (*playerMove) - 1;
    int idxAiMove = (*aiMove) - 1;

    if (idxPlayerMove < 0) {
        idxPlayerMove = 0;
    }

    if (idxAiMove < 0) {
        idxAiMove = 0;
    }

    std::cout << "\nPLAYER - " << possiblePlays[idxPlayerMove] << " x " << possiblePlays[idxAiMove] << " - AI"  << std::endl;

    int resultIndex = -1;

    switch (*playerMove)
    {
    //Player played Rock
    case 1:
        //Rock vs Rock = Draw
        if (*aiMove == 1) resultIndex = 0;
        //Rock vs Paper = AI Win
        if (*aiMove == 2) resultIndex = 2;
        //Rock vs Scissors = Player Win
        if (*aiMove == 3) resultIndex = 1;
        break;

    //Player played Paper
    case 2:
        //Paper vs Rock = Player Win
        if (*aiMove == 1) resultIndex = 1;
        //Paper vs Paper = Draw
        if (*aiMove == 2) resultIndex = 0;
        //Paper vs Scissors = AI Win
        if (*aiMove == 3) resultIndex = 2;
        break;

    //Player played Scissors
    case 3:
        //Scissors vs Rock = AI Win
        if (*aiMove == 1) resultIndex = 2;
        //Scissors vs Paper = Player Win
        if (*aiMove == 2) resultIndex = 1;
        //Scissors vs Scissors = Draw
        if (*aiMove == 3) resultIndex = 0;
        break;
    }

    return resultIndex;
}

static void runMatch(int* option, int* scorePlayer, int* scoreAI) 
{
    int aiMove = getAIMove();
    int resultIndex = treatMoves(option, &aiMove);

    if (resultIndex == 1) 
    {
        (*scorePlayer)++;
        std::cout << "Player wins!" << std::endl;
    }
    else if (resultIndex == 2) 
    {
        (*scoreAI)++;
        std::cout << "AI wins!" << std::endl;
    }
    else 
    {
        std::cout << "Oh, it's a draw..." << std::endl;
    }

    std::cout << "\n";
}
#pragma endregion

int main()
{
    int scorePlayer = 0;
    int scoreAI = 0;

    bool isGameRunning = false;

    printHeader();
    printMainMenu();
    
    if (canInitGame()) {
        clearScreen();
        isGameRunning = true;

        do
        {
            printScore(&scorePlayer, &scoreAI);
            printMatchOptions();

            int option = getPlayerInput(3);

            if (option == 0)
            {
                isGameRunning = false;
                clearScreen();
                printMainMenu();

                if (canInitGame()) {
                    clearScreen();
                    isGameRunning = true;
                }
            }
            else 
            {
                runMatch(&option, &scorePlayer, &scoreAI);

                system("PAUSE");
                clearScreen();
            }
        } while (isGameRunning);
    }
    else {
        exit(0);
    }

    return 0;
}