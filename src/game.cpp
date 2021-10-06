#include "../include/game.h"
#include <iostream>

Game::Game() : 
    m_isRunning(true)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
}

void Game::init(std::string t_windowName, int t_width, int t_height)
{
    Window* sdlImp = new SDL_Window_Imp();
    sdlImp->init(t_windowName, 1366, 768);

    //Window* sfmlImp = new SFML_Window_Imp();
    //sfmlImp->init(t_windowName, t_width, t_height);

    m_rendering.push_back(sdlImp);
    //m_rendering.push_back(sfmlImp);
}

void Game::handleInputs()
{
    for(auto& e : m_rendering)
        m_isRunning = e->handleInputs();
}

void Game::update()
{
}

void Game::render()
{
    for(auto& e : m_rendering)
            e->draw();
}

void Game::cleanup()
{
    std::cout << "Finished Cleaning\n";
}

bool Game::isRunning()
{
    return m_isRunning;
}