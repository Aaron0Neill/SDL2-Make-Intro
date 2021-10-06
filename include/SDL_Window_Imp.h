#pragma once
#include "window.h"
#include <SDL.h>
#include <SDL_image.h>

class SDL_Window_Imp : public Window
{
public:

    SDL_Window_Imp();
    virtual ~SDL_Window_Imp();

    virtual void init(std::string t_windowName, int t_width, int t_height)override;

    virtual void draw()override;

    virtual bool handleInputs()override;
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};