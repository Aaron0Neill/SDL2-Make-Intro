/*#include "../include/SFML_Window_Imp.h"

SFML_Window_Imp::SFML_Window_Imp()
{

}

SFML_Window_Imp::~SFML_Window_Imp()
{
    delete m_window;
}

void SFML_Window_Imp::init(std::string t_windowName, int t_width, int t_height)
{
    m_window = new sf::RenderWindow(sf::VideoMode(t_width,t_height), t_windowName);
}

bool SFML_Window_Imp::handleInputs()
{
    sf::Event currentEvent;
	while (m_window->pollEvent(currentEvent))
	{
		if (sf::Event::Closed == currentEvent.type)
		{
			return false;
		}
    }
    return true;
}

void SFML_Window_Imp::draw()
{
    m_window->clear();

    m_window->display();
}*/