
#ifndef ABSTRACT_INPUT_ARRAY_HEADER
#define ABSTRACT_INPUT_ARRAY_HEADER

#include <map>
#include <list>
#include <SFML/Graphics.hpp>
#include <functional>


/*
Class used to check the state of inputs without dealing with event handling
This abstraction allows an input-simulating class to be used instead of user inputs
*/
class AbstractInputs
{
    public :

    virtual ~AbstractInputs() {}

    virtual bool closeWindow() const = 0;           // true when the window must be closed or the escape key is pressed
    virtual sf::Vector2f cursor() const = 0;        // cursor position

    virtual void update(float dt = 0) = 0;          // the number of ticks is not really important

    std::map<sf::Mouse::Button, bool>& getMouseButtons();                          // these four methods all return the
    std::map<sf::Keyboard::Key , bool>& getKeyboardButtons();                      // same value as _get[m|k]Buttons()

    const std::map<sf::Mouse::Button, bool>& getMouseButtons() const;              // their name is different to avoid
    const std::map<sf::Keyboard::Key , bool>& getKeyboardButtons() const;          // inheritance problems with name overloading

    std::list<sf::Mouse::Button> getPressedMouseButtons() const;                   // array of pressed mouse buttons
    std::list<sf::Keyboard::Key> getPressedKeyboardButtons() const;                // array of pressed keyboard keys

    using mouseEvent = std::function<void(bool/*pressed*/,sf::Vector2f/*cursorPosition*/)>;
    using keyboardEvent = std::function<void(bool/*pressed*/)>;

    virtual void setMouseButtonEvents(std::map<sf::Mouse::Button, mouseEvent> events) = 0;
    virtual void setKeyboardButtonEvents(std::map<sf::Keyboard::Key, keyboardEvent> events) = 0;

    bool isAnyMouseButtonPressed() const;
    bool isAnyKeyPressed() const;


    protected :

    virtual std::map<sf::Mouse::Button, bool>& _getMouseButtons() = 0;             // map of all mouse buttons
    virtual std::map<sf::Keyboard::Key , bool>& _getKeyboardButtons() = 0;         // map of all keyboard keys
};


#endif

