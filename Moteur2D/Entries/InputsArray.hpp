
#ifndef INPUTS_ARRAY_HEADER
#define INPUTS_ARRAY_HEADER

#include <SFML/Graphics.hpp>
#include "InputsAbstraction.hpp"


// Class used to check the state of the inputs and easy events handling
class Inputs : public InputsAbstraction
{
    public :

    explicit Inputs(sf::Window* window = nullptr, bool escapeMeansClose = true);
    void set(sf::Window* window, bool escapeMeansClose = true);

    bool closeWindow() const;                                   // true when the window must be closed or the escape key is pressed
    sf::Vector2f cursor() const;                                // cursor position
    int mouseWheel() const;
    void resetMouseWheel();

    void update(float dt, bool resetWheel = true);


    protected :

    std::map<sf::Mouse::Button, bool>& _getMouseButtons();      // map of mouse buttons
    std::map<sf::Keyboard::Key, bool>& _getKeyboardButtons();   // map of keyboard keys


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


#endif // INPUTS_ARRAY_HEADER
