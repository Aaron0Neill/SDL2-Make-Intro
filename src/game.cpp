#include "../include/game.h"
#include <iostream>

Game::Game() : 
    m_isRunning(true)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
}

void Game::init(std::string t_windowName, int t_x, int t_y, int t_width, int t_height, Uint32 t_flags)
{
    m_window = SDL_CreateWindow(t_windowName.c_str(), t_x, t_y, t_width, t_height, t_flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    
    SDL_Surface* tempSurf = IMG_Load("assets/Circle.png");

    if (tempSurf == nullptr)
    {
        printf(SDL_GetError());
    }

    m_image =  SDL_CreateTextureFromSurface(m_renderer, tempSurf);

    if (m_image == nullptr)
    {
        printf(SDL_GetError()); 
    }

    SDL_QueryTexture(m_image, NULL, NULL, &m_imageRect.w, &m_imageRect.h);
    m_imageRect.w /= 2;
    m_imageRect.h /= 2;

    SDL_FreeSurface(tempSurf);
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
                break;
            case SDL_MOUSEMOTION:
                m_imageRect.x = event.button.x - m_imageRect.w /2;
                m_imageRect.y = event.button.y - m_imageRect.h /2;
                break;
            case SDL_MOUSEBUTTONDOWN:
                m_imageRect.w *= 2;
                m_imageRect.h *= 2;
                m_imageRect.x = event.button.x - m_imageRect.w /2;
                m_imageRect.y = event.button.y - m_imageRect.h /2;
                break;
            case SDL_MOUSEBUTTONUP:
                m_imageRect.w /= 2;
                m_imageRect.h /= 2;
                m_imageRect.x = event.button.x - m_imageRect.w /2;
                m_imageRect.y = event.button.y - m_imageRect.h /2;
                break;
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
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);
    SDL_RenderDrawRect(m_renderer, &m_player.getPlayer());

    SDL_RenderCopy(m_renderer, m_image, NULL, &m_imageRect);


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