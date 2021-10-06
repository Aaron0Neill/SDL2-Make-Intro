#pragma once
#include "window.h"
#include <SFML/Graphics.hpp>


class SFML_Window_Imp : public Window
{
public:
    SFML_Window_Imp();
    virtual ~SFML_Window_Imp();

    virtual void init(std::string t_windowName, int t_width, int t_height)override;

    virtual bool handleInputs()override;
    virtual void draw()override;
private:
    sf::RenderWindow* m_window;
};