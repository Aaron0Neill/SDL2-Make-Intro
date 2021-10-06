#include "../include/SDL_Window_Imp.h"

SDL_Window_Imp::SDL_Window_Imp()
{

}

SDL_Window_Imp::~SDL_Window_Imp()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}

void SDL_Window_Imp::init(std::string t_windowName, int t_width, int t_height)
{
    m_window = SDL_CreateWindow(t_windowName.c_str(), 100, 100, t_width, t_height, SDL_WINDOW_INPUT_FOCUS);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

bool SDL_Window_Imp::handleInputs()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                return false;
                break;
        }
    }
    return true;
}

void SDL_Window_Imp::draw()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);


    SDL_RenderPresent(m_renderer);
}