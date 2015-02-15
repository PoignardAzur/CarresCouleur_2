
#include "InputsAbstraction.hpp"


void InputsAbstraction::update(float dt, bool resetWheel) // the number of ticks is not really important
{
    (void) dt;
    (void) resetWheel;

    m_events.remove_if
    (
        [](const std::unique_ptr<EventsMap>& eventMap_ptr)
        {
            return eventMap_ptr->toDelete();
        }
    );
}


const std::map<sf::Mouse::Button, bool>& InputsAbstraction::getMouseButtons() const
{
    return const_cast<InputsAbstraction*>(this)->_getMouseButtons();
}

const std::map<sf::Keyboard::Key , bool>& InputsAbstraction::getKeyboardButtons() const
{
    return const_cast<InputsAbstraction*>(this)->_getKeyboardButtons();
}

std::map<sf::Mouse::Button, bool>& InputsAbstraction::getMouseButtons()
{
    return _getMouseButtons();
}

std::map<sf::Keyboard::Key , bool>& InputsAbstraction::getKeyboardButtons()
{
    return _getKeyboardButtons();
}

std::list<sf::Mouse::Button> InputsAbstraction::getPressedMouseButtons() const // array of pressed mouse buttons
{
    std::list<sf::Mouse::Button> pmb;

    for (const auto& b : getMouseButtons())
    {
        if (b.second)
        pmb.push_back(b.first);
    }

    return pmb;
}

std::list<sf::Keyboard::Key> InputsAbstraction::getPressedKeyboardButtons() const // list of pressed keyboard keys
{
    std::list<sf::Keyboard::Key> pkb;

    for (const auto& k : getKeyboardButtons())
    {
        if (k.second)
        pkb.push_back(k.first);
    }

    return pkb;
}


void InputsAbstraction::addEventsMap(std::unique_ptr<EventsMap> eventsMap) // adds eventsMap to a list of EventsMap
{
    m_events.push_back(std::move(eventsMap));
}

void InputsAbstraction::trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursorPosition) // uses the respective trigger() method for every EventsMap
{
    for (auto& eventMap_ptr : m_events)
    {
        eventMap_ptr->trigger(button, pressed, cursorPosition);
    }
}

void InputsAbstraction::trigger(sf::Keyboard::Key key, bool pressed) // uses the respective trigger() method for every EventsMap
{
    for (auto& eventMap_ptr : m_events)
    {
        eventMap_ptr->trigger(key, pressed);
    }
}


bool InputsAbstraction::isAnyMouseButtonPressed() const
{
    for (const auto& b : getMouseButtons())
    {
        if (b.second)
        return true;
    }

//  default
    return false;
}

bool InputsAbstraction::isAnyKeyPressed() const
{
    for (const auto& k : getKeyboardButtons())
    {
        if (k.second)
        return true;
    }

//  default
    return false;
}

