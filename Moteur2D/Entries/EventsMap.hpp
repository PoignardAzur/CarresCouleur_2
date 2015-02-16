
#ifndef EVENTS_MAP_HEADER
#define EVENTS_MAP_HEADER

#include <map>
#include <functional>
#include <SFML/Graphics.hpp>


/*
Class used with InputsAbstraction to provide simple event-handling mechanics.
This class keeps function objects pointing to an outside Interface,
which is why it's marked for deletion by the Interface's destructor
POINTER SAFETY : The function objects must be safe as long as
the interface that created this instance has not been deleted
*/
class EventsMap
{
    public :

    using MouseEvent = std::function<void(bool/*pressed*/,sf::Vector2f/*cursorPosition*/)>;
    using KeyboardEvent = std::function<void(bool/*pressed*/)>;

    using MouseEventsMap = std::map<sf::Mouse::Button, MouseEvent>;
    using KeyboardEventsMap = std::map<sf::Keyboard::Key, KeyboardEvent>;

    EventsMap() = default;
    EventsMap(EventsMap&& other);
    EventsMap(MouseEventsMap mouseButtonEvents, KeyboardEventsMap keyboardButtonEvents);
    void set(MouseEventsMap mouseButtonEvents, KeyboardEventsMap keyboardButtonEvents);

    void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursorPosition);
    void trigger(sf::Keyboard::Key key, bool pressed);

    void remove();
    bool toDelete() const;


    private :

    MouseEventsMap m_mouseButtonEvents;
    KeyboardEventsMap m_keyboardButtonEvents;

    bool m_toDelete = false;
};


#endif // EVENTS_MAP_HEADER
