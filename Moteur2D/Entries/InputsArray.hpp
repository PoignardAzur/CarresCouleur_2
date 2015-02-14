

#ifndef INPUTS_ARRAY
#define INPUTS_ARRAY

#include <SFML/Graphics.hpp>
#include "InputsAbstraction.hpp"


// Class used to check the state of inputs without dealing with event handling
class Inputs : public InputsAbstraction
{
    public :

    explicit Inputs(sf::Window* fenetre = nullptr, bool escapeMeansClose = true);
    void set(sf::Window* fenetre, bool escapeMeansClose = true);

    bool closeWindow() const;             // true when the window must be closed
    sf::Vector2f cursor() const;          // cursor position
    int mouseWheel() const;
    void resetMouseWheel() const;

    void update(float dt, bool resetWheel = true);

    //using mouseEvent = std::function<void(bool/*pressed*/,sf::Vector2f/*cursorPosition*/)>;
    //using keyboardEvent = std::function<void(bool/*pressed*/)>;

    void addEvents(std::unique_ptr<EventsMap> events);


    protected :

    std::map<sf::Mouse::Button, bool>& _getMouseButtons();           // map of mouse buttons
    std::map<sf::Keyboard::Key, bool>& _getKeyboardButtons();        // map of keyboard keys


    private :

    sf::Window* m_fenetre;  // use-a
    sf::Event m_event;

    std::map<sf::Mouse::Button, bool> t_boutonsSouris;
    std::map<sf::Keyboard::Key , bool> t_boutonsClavier;
    sf::Vector2f m_cursor;
    int m_mouseWheel;

    bool m_closeWindow = false;
    bool m_escapeMeansClose;

};


#endif // INPUTS_ARRAY
