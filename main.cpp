#include "game.h"
#include <string>

int main(int argc, char** argv)
{
    Game* game = new Game();
    game->init("DGPP Skelatol", 150,250,1366,768, SDL_WINDOW_INPUT_FOCUS);
    std::cout << "Loop Starting\n";

    while (game->isRunning())
    {
        game->handleInputs();
        game->update();
        game->render();
    }
    std::cout << "Cleaning up\n";
    game->cleanup();
    return 0;
}