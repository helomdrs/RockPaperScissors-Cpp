#include "PrintManager.h"
#include "InputManager.h"
#include "GameManager.h"

int main()
{
    PrintManager printManager;
    InputManager inputManager;
    GameManager gameManager(&inputManager, &printManager);

    gameManager.StartGame();

    if (!gameManager.CanInitGame()) return 0;

    while (gameManager.isGameRunning)
    {
        gameManager.Update();
    };

    return 0;
}