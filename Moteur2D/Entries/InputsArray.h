

#ifndef TABLEAU_ENTREES
#define TABLEAU_ENTREES

#include <SFML/Graphics.hpp>
#include "AbstractInputsArray.h"


// Class used to check the state of inputs without dealing with event handling
class Inputs : public AbstractInputs
{
    public :

    explicit Inputs(sf::Window* fenetre = nullptr, bool escapeMeansClose = true);
    void set(sf::Window* fenetre, bool escapeMeansClose = true);

    bool closeWindow() const;             // true when the window must be closed
    sf::Vector2f cursor() const;          // cursor position

    void update(float dt);


    protected :

    std::map<sf::Mouse::Button, bool>& _mouseButtons();           // map of mouse buttons
    std::map<sf::Keyboard::Key , bool>& _keyboardButtons();       // map of keyboard keys


    private :

    sf::Window* m_fenetre;  // use-a
    sf::Event m_event;

    std::map<sf::Mouse::Button, bool> t_boutonsSouris;
    std::map<sf::Keyboard::Key , bool> t_boutonsClavier;
    sf::Vector2f m_cursor;
    int m_molette;

    bool m_closeWindow = false;
    bool m_escapeMeansClose;

};




#endif



