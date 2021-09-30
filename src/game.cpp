#include "../include/game.h"

Game::Game() : 
    m_isRunning(true)
{
}

void Game::init(std::string t_windowName, int t_x, int t_y, int t_width, int t_height, Uint32 t_flags)
{
    m_window = SDL_CreateWindow(t_windowName.c_str(), t_x, t_y, t_width, t_height, t_flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::handleInputs()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                m_isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == 'w')
                {
                    m_player.moveUp();
                }
                else if (event.key.keysym.sym == 'a')
                {
                    m_player.moveLeft();
                }
                else if (event.key.keysym.sym == 's')
                {
                    m_player.moveDown();
                }
                else if (event.key.keysym.sym == 'd')
                {
                    m_player.moveRight();
                }
            default:
                break;
        }
    }
}

void Game::update()
{
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(m_renderer, &m_player.getPlayer());


    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);


    SDL_RenderPresent(m_renderer);
}

void Game::cleanup()
{
    SDL_DestroyWindow(m_window);
    std::cout << "Finished Cleaning\n";
}

bool Game::isRunning()
{
    return m_isRunning;
}