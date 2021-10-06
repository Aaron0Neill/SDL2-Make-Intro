#include <iostream>
#include <SDL.h>
#include "player.h"
#include <string>
#include <SDL_image.h>

class Game
{
public:
    Game();
    ~Game() = default;

    void init(std::string t_windowName, int t_x, int t_y, int t_width, int t_height, Uint32 t_flags);

    void handleInputs();
    void update();
    void render();

    void cleanup();

    bool isRunning();
private:

    bool m_isRunning;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    Player m_player;
    SDL_Texture* m_image;
    SDL_Rect m_imageRect;
};