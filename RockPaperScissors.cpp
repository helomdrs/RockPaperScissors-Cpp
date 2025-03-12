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

static void printScore(int scorePlayer, int scoreAI)
{
    std::cout << "                   PLAYER " << scorePlayer << " x " << scoreAI << " AI" <<  std::endl;
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

static int getPlayerInput(int lastOption)
{
    int input = 0;
    std::cin >> input;

    while (std::cin.fail() || (input > lastOption || input < 0))
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

   toInitGame = getPlayerInput(2) == 1;

   return toInitGame;
}

#pragma region Match Methods

static int getAIMove() 
{
    int aiMove = std::rand() % 3;
    return aiMove;
}

//using ENUM because it makes more sense for the code than structs
enum Result
{
    Draw,
    PlayerWon,
    AIWon
};

//a copy of a variable costs less memory than a pointer, prefer to use pointers on Objects references
//if a variable will be modified, use reference (&) instead
static Result getMatchResult(int playerMove, int aiMove) {

    std::cout << "\nPLAYER - " << possiblePlays[playerMove] << " x " << possiblePlays[aiMove] << " - AI" << std::endl;

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

static void runMatch(int playerMove, int &scorePlayer, int &scoreAI) 
{
    int aiMove = getAIMove();
    Result matchResult = getMatchResult(playerMove, aiMove);

    if (matchResult == Result::Draw) {
        std::cout << "Oh, it's a draw..." << std::endl;
    }
    else {
        if (matchResult == Result::PlayerWon) {
            scorePlayer++;
            std::cout << "Player wins!" << std::endl;
        } 

        if (matchResult == Result::AIWon) {
            scoreAI++;
            std::cout << "AI wins!" << std::endl;
        }
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
            printScore(scorePlayer, scoreAI);
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
                runMatch(option - 1, scorePlayer, scoreAI);

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