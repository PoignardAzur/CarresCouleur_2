
#ifndef ABSTRACT_INPUT_ARRAY_HEADER
#define ABSTRACT_INPUT_ARRAY_HEADER

#include <map>
#include <list>
#include <SFML/Graphics.hpp>


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

    virtual void update(float dt = 0) = 0;       // the number of ticks is not really important

    std::map<sf::Mouse::Button, bool>& mouseButtons();                          // these four methods all return the
    std::map<sf::Keyboard::Key , bool>& keyboardButtons();                      // same value as _[m|k]Buttons()

    const std::map<sf::Mouse::Button, bool>& mouseButtons() const;              // their name is different to avoid
    const std::map<sf::Keyboard::Key , bool>& keyboardButtons() const;          // inheritance problems with name overloading

    std::list<sf::Mouse::Button> pressedMouseButtons() const;          // array of pressed mouse buttons
    std::list<sf::Keyboard::Key> pressedKeyboardButtons() const;       // array of pressed keyboard keys

    bool anyMouseButtonPressed() const;
    bool anyKeyPressed() const;


    protected :

    virtual std::map<sf::Mouse::Button, bool>& _mouseButtons() = 0;             // map of all mouse buttons
    virtual std::map<sf::Keyboard::Key , bool>& _keyboardButtons() = 0;         // map of all keyboard keys
};


#endif

