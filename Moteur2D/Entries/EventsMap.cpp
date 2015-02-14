
#include "EventsMap.hpp"


EventsMap::EventsMap(EventsMap&& other)
{
    set(std::move(other.m_mouseButtonEvents), std::move(other.m_keyboardButtonEvents));
}

EventsMap::EventsMap(mouseEventsMap mouseButtonEvents, keyboardEventsMap keyboardButtonEvents)
{
    set(mouseButtonEvents, keyboardButtonEvents);
}

void EventsMap::set(mouseEventsMap mouseButtonEvents, keyboardEventsMap keyboardButtonEvents)
{
    m_mouseButtonEvents = std::move(mouseButtonEvents);
    m_keyboardButtonEvents = std::move(keyboardButtonEvents);
}


void EventsMap::trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursorPosition)
{
    if (m_mouseButtonEvents.count(button))
    m_mouseButtonEvents[button](pressed, cursorPosition);
}

void EventsMap::trigger(sf::Keyboard::Key key, bool pressed)
{
    if (m_keyboardButtonEvents.count(key))
    m_keyboardButtonEvents[key](pressed);
}

void EventsMap::remove()
{
    m_toDelete = true;
}

bool EventsMap::toDelete() const
{
    return m_toDelete;
}

