


#include "InputsArray.h"



Inputs::Inputs(sf::Window* window, bool escapeMeansClose)
{
    set(window, escapeMeansClose);
}

void Inputs::set(sf::Window* window, bool escapeMeansClose)
{
    m_fenetre = window;
    m_escapeMeansClose = escapeMeansClose;
}

bool Inputs::closeWindow() const
{
    return m_closeWindow;
}

sf::Vector2f Inputs::cursor() const
{
    return m_cursor;
}

void Inputs::update(float dt)
{
    if (!m_fenetre)
    return;

    m_molette = 0;

    while (m_fenetre->pollEvent(m_event))
    {
        switch(m_event.type)
        {
            case sf::Event::MouseWheelMoved : // Counts the number of mouse wheel ticks (most of the times, one)
            m_molette += m_event.mouseWheel.delta;
            break;

            case sf::Event::MouseButtonPressed : // A mouse button is pressed
            t_boutonsSouris[m_event.mouseButton.button] = true;
            break;

            case sf::Event::MouseButtonReleased : // A mouse button is released
            t_boutonsSouris[m_event.mouseButton.button] = false;
            break;

            case sf::Event::KeyPressed : // Same for keyboard buttons
            t_boutonsClavier[m_event.key.code] = true;

            if (m_event.key.code == sf::Keyboard::Escape && m_escapeMeansClose) // In simple games, pressing escape can be a
            m_closeWindow = true;                                               // shortcut to exit the game (as well as Alt+F4)

            break;

            case sf::Event::KeyReleased :
            t_boutonsClavier[m_event.key.code] = false;
            break;


            case sf::Event::MouseMoved : // Sets the new mouse position (the relative moving is not tracked)
            m_cursor.x = m_event.mouseMove.x;
            m_cursor.y = m_event.mouseMove.y;
            break;

            case sf::Event::Closed : // Detects attempts to close the window (Alt+F4, Red X, etc)
            m_closeWindow = true;
            break;

            default :

            break;
        }
    }
}

std::map<sf::Mouse::Button, bool>& Inputs::_mouseButtons()
{
    return t_boutonsSouris;
}

std::map<sf::Keyboard::Key, bool>& Inputs::_keyboardButtons()
{
    return t_boutonsClavier;
}




