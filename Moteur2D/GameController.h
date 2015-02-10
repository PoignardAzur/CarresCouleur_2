

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE

#include "Interfaces/AbstractLevel.h"
#include "Graphic/ObjectDrawer.h"
#include <memory>


//Abstraction of a singleton that controls the entire game.
class GameController
{
    public :

    GameController(up_t<AbstractInputs> userInputs, sf::RenderWindow* target);
    virtual ~GameController() {}

    virtual void update(float dt);                               // THIS MUST BE DEVELOPPED IN THE CHILD CLASS
    virtual bool isDone() const = 0;                             // THIS MUST BE DEVELOPPED IN THE CHILD CLASS

    protected :

    AbstractInputs* windowInputs();
    AbstractDrawer* renderingWindow();
    virtual AbstractGameInterface<float>* interface() = 0;       // THIS MUST BE DEVELOPPED IN THE CHILD CLASS


    private :

    up_t<AbstractInputs> m_userInputs;     // has-a
    up_t<AbstractDrawer> m_window;         // has-a

    sf::RenderWindow* m_renderWindow;                 // use-a
};


#endif
