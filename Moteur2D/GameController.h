

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE

#include "Interfaces/AbstractLevel.h"
#include "Graphic/ObjectDrawer.h"
#include <memory>


//Abstraction of a singleton that controls the entire game.
class GameController
{
    public :

    GameController(AbstractInputs* userInputs, sf::RenderWindow* target);
    virtual void update(float dt);                               // THIS MUST BE DEVELOPPED IN THE CHILD CLASS
    virtual bool isDone() const = 0;                             // THIS MUST BE DEVELOPPED IN THE CHILD CLASS

    protected :

    AbstractInputs* windowInputs();
    AbstractDrawer* renderingWindow();
    virtual AbstractGameInterface<float>* interface() = 0;       // THIS MUST BE DEVELOPPED IN THE CHILD CLASS


    private :

    std::unique_ptr<AbstractInputs> m_userInputs;     // has-a
    std::unique_ptr<AbstractDrawer> m_window;         // has-a

    sf::RenderWindow* m_renderWindow;                 // use-a
};


#endif
