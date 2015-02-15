
#ifndef GAME_CONTROLLER_HEADER
#define GAME_CONTROLLER_HEADER

#include "Interfaces/AbstractLevel.hpp"
#include "Graphic/ObjectDrawer.hpp"
#include <memory>
#include "up.hpp"


//Abstraction of a singleton that controls the entire game.
class GameController
{
    public :

    GameController(up_t<InputsAbstraction> userInputs, sf::RenderWindow* target);
    virtual ~GameController() {}

    virtual void update(float dt);                               // THIS MUST BE DEVELOPPED IN THE CHILD CLASS
    virtual bool isDone() const = 0;                             // THIS MUST BE DEVELOPPED IN THE CHILD CLASS
    virtual void display(float dt);


    protected :

    InputsAbstraction& windowInputs();
    DrawerAbstraction& renderingWindow();
    virtual AbstractGameInterface& interface() = 0;       // THIS MUST BE DEVELOPPED IN THE CHILD CLASS


    private :

    up_t<InputsAbstraction> m_userInputs;
    up_t<DrawerAbstraction> m_window;

    sf::RenderWindow* m_renderWindow; // use-a
};


#endif // GAME_CONTROLLER_HEADER
