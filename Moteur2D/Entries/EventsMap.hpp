
#ifndef EVENTS_MAP_HEADER
#define EVENTS_MAP_HEADER

#include <map>
#include <functional>
#include <SFML/Graphics.hpp>


/*
Class used with InputsAbstraction to provide simple event-handling mechanics.
This class keeps function objects pointing to an outside Interface,
which is why it's marked for deletion by the Interface's destructor
*/
class EventsMap
{
    public :

    using mouseEvent = std::function<void(bool/*pressed*/,sf::Vector2f/*cursorPosition*/)>;
    using keyboardEvent = std::function<void(bool/*pressed*/)>;

    using mouseEventsMap = std::map<sf::Mouse::Button, mouseEvent>;
    using keyboardEventsMap = std::map<sf::Keyboard::Key, keyboardEvent>;

    EventsMap() = default;
    EventsMap(EventsMap&& other);
    EventsMap(mouseEventsMap mouseButtonEvents, keyboardEventsMap keyboardButtonEvents);
    void set(mouseEventsMap mouseButtonEvents, keyboardEventsMap keyboardButtonEvents);

    void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursorPosition);
    void trigger(sf::Keyboard::Key key, bool pressed);

    void remove();
    bool toDelete() const;


    private :

    std::map<sf::Mouse::Button, mouseEvent> m_mouseButtonEvents;
    std::map<sf::Keyboard::Key, keyboardEvent> m_keyboardButtonEvents;

    bool m_toDelete = false;
};


#endif // EVENTS_MAP_HEADER
