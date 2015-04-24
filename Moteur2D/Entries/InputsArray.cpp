
#include "InputsArray.hpp"


Inputs::Inputs(sf::Window* window, bool escapeMeansClose)
{
    set(window, escapeMeansClose);
}

void Inputs::set(sf::Window* window, bool escapeMeansClose)
{
    m_fenetre = window;
    m_escapeMeansClose = escapeMeansClose;
}

bool Inputs::closeWindow() const // true when the window must be closed or the escape key is pressed
{
    return m_closeWindow;
}

sf::Vector2f Inputs::cursor() const
{
    return m_cursor;
}

int Inputs::mouseWheel() const
{
    return m_mouseWheel;
}

void Inputs::resetMouseWheel()
{
    m_mouseWheel = 0;
}


void Inputs::update(float dt, bool resetWheel)
{
    InputsAbstraction::update(dt);

    if (!m_fenetre)
    return;

    (void) dt;

    if (resetWheel)
    resetMouseWheel();

    /* This function asks the window for events that have happened since the last update ;
    the rest of the loop handles the given events */
    while (m_fenetre->pollEvent(m_event))
    {
        switch(m_event.type)
        {
            case sf::Event::MouseButtonPressed : // A mouse button is pressed
                t_boutonsSouris[m_event.mouseButton.button] = true;
                trigger(m_event.mouseButton.button, true, m_cursor);
            break;

            case sf::Event::MouseButtonReleased : // A mouse button is released
                t_boutonsSouris[m_event.mouseButton.button] = false;
                trigger(m_event.mouseButton.button, false, m_cursor);
            break;

            case sf::Event::KeyPressed : // Same for keyboard buttons
                t_boutonsClavier[m_event.key.code] = true;
                trigger(m_event.key.code, true);

                if (m_event.key.code == sf::Keyboard::Escape && m_escapeMeansClose) // In simple games, pressing escape can be a
                m_closeWindow = true;                                               // shortcut to exit the game (as well as Alt+F4)
            break;

            case sf::Event::KeyReleased :
                t_boutonsClavier[m_event.key.code] = false;
                trigger(m_event.key.code, false);
            break;


            case sf::Event::MouseWheelMoved : // Counts the number of mouse wheel ticks (most of the times, one)
                m_mouseWheel += m_event.mouseWheel.delta;
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

std::map<sf::Mouse::Button, bool>& Inputs::_getMouseButtons()
{
    return t_boutonsSouris;
}

std::map<sf::Keyboard::Key, bool>& Inputs::_getKeyboardButtons()
{
    return t_boutonsClavier;
}

