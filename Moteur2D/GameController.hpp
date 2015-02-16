
#ifndef GAME_CONTROLLER_HEADER
#define GAME_CONTROLLER_HEADER

#include "Interfaces/Level.hpp"
#include "Graphic/ObjectDrawer.hpp"
#include <memory>
#include "up.hpp"


/*
Abstraction of a singleton that controls the entire game.
POINTER SAFETY : 'display()' must not be called after 'target' is deleted
*/
class GameController
{
    public :

    GameController(uptrt<InputsAbstraction> userInputs, sf::RenderWindow* target);
    virtual ~GameController() {}

    virtual void update(float dt);                               // THIS MUST BE DEVELOPPED IN THE CHILD CLASS
    virtual bool isDone() const = 0;                             // THIS MUST BE DEVELOPPED IN THE CHILD CLASS
    virtual void display(float dt);


    protected :

    InputsAbstraction& windowInputs();
    DrawerAbstraction& renderingWindow();
    virtual GameInterfaceAbstraction& interface() = 0;       // THIS MUST BE DEVELOPPED IN THE CHILD CLASS


    private :

    uptrt<InputsAbstraction> m_userInputs;
    uptrt<DrawerAbstraction> m_window;

    sf::RenderWindow* m_renderWindow; // use-a
};


#endif // GAME_CONTROLLER_HEADER
