#include "PrintManager.h"
#include "InputManager.h"
#include "GameManager.h"

int main()
{
    PrintManager printManager;
    InputManager inputManager;
    GameManager gameManager(&inputManager, &printManager);

    printManager.printHeader();
    printManager.printMainMenu();
    
    if (gameManager.canInitGame()) {
        printManager.clearScreen();
        gameManager.isGameRunning = true;

        do
        {
            printManager.printScore(gameManager.scorePlayer, gameManager.scoreAI);
            printManager.printMatchOptions();

            int option = inputManager.getPlayerInput(3);

            if (option == 0)
            {
                gameManager.isGameRunning = false;
                printManager.clearScreen();
                printManager.printMainMenu();

                if (gameManager.canInitGame()) {
                    printManager.clearScreen();
                    gameManager.isGameRunning = true;
                }
            }
            else 
            {
                gameManager.runMatch(option - 1, gameManager.scorePlayer, gameManager.scoreAI);

                system("PAUSE");
                printManager.clearScreen();
            }
        } while (gameManager.isGameRunning);
    }
    return 0;
}