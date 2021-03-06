
#ifndef INPUT_ARRAY_ABSTRACTION_HEADER
#define INPUT_ARRAY_ABSTRACTION_HEADER

#include <list>
#include <memory>
#include "EventsMap.hpp"


/*
Class used to check the state of the inputs and easy events handling
This abstraction allows an input-simulating class to be used instead of user inputs
POINTER SAFETY : The given EventsMaps have to be safe
*/
class InputsAbstraction
{
    public :

    virtual ~InputsAbstraction() = default;

    virtual bool closeWindow() const = 0;           // true when the window must be closed or the escape key is pressed
    virtual sf::Vector2f cursor() const = 0;        // cursor position
    virtual int mouseWheel() const = 0;
    virtual void resetMouseWheel() = 0;             // after calling this method, mouseWheel() is always worth 0

    virtual void update(float dt = 0, bool resetWheel = true) = 0;          // the number of ticks is not really important

    std::map<sf::Mouse::Button, bool>& getMouseButtons();                   // these four methods all return the
    std::map<sf::Keyboard::Key, bool>& getKeyboardButtons();                // same value as _get[m|k]Buttons()

    const std::map<sf::Mouse::Button, bool>& getMouseButtons() const;       // their name is different to avoid
    const std::map<sf::Keyboard::Key, bool>& getKeyboardButtons() const;    // inheritance problems with name overloading

    std::list<sf::Mouse::Button> getPressedMouseButtons() const;            // array of pressed mouse buttons
    std::list<sf::Keyboard::Key> getPressedKeyboardButtons() const;         // array of pressed keyboard keys

    bool isPressed(sf::Mouse::Button button) const;
    bool isPressed(sf::Keyboard::Key key) const;

    void addEventsMap(std::unique_ptr<EventsMap> eventsMap);                // adds eventsMap to a list of EventsMap (m_events)

    bool isAnyMouseButtonPressed() const;
    bool isAnyKeyPressed() const;


    protected :

    void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursorPosition);
    void trigger(sf::Keyboard::Key key, bool pressed);                      // uses the respective trigger() method for every EventsMap

    virtual std::map<sf::Mouse::Button, bool>& _getMouseButtons() = 0;      // map of all mouse buttons
    virtual std::map<sf::Keyboard::Key , bool>& _getKeyboardButtons() = 0;  // map of all keyboard keys


    private :

    std::list<std::unique_ptr<EventsMap>> m_events;
};


#endif // INPUT_ARRAY_ABSTRACTION_HEADER
