
#include <iostream>
#include <SDL.h>

class Player
{
public:
    Player();
    ~Player();

    void init(int xPos = 250, int yPos = 250, int width = 100, int height = 100);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    SDL_Rect& getPlayer();

private:
    SDL_Rect m_body;
};