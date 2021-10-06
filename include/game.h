#pragma once
#include <iostream>
#include "SDL_Window_Imp.h"
#include "SFML_Window_Imp.h"
#include "player.h"
#include <string>
#include <vector>

class Game
{
public:
    Game();
    ~Game() = default;

    void init(std::string t_windowName, int t_width, int t_height);

    void handleInputs();
    void update();
    void render();

    void cleanup();

    bool isRunning();
private:

    bool m_isRunning;
    std::vector<Window*> m_rendering;
    Player m_player;
};