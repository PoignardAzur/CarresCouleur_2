

#ifndef ABSTRACT_GAME_INTERFACE_HEADER
#define ABSTRACT_GAME_INTERFACE_HEADER

#include "../Entries/InputsArray.hpp"
#include "../Graphic/DrawerAbstraction.hpp"
#include "up.hpp"


class AbstractGameInterface
{
    public :

    AbstractGameInterface();
    virtual ~AbstractGameInterface();

    virtual void drawIn(DrawerAbstraction& window, float dt) const = 0;

    using mouseEventsMap = std::map<sf::Mouse::Button, InputsAbstraction::mouseEvent>;
    using keyboardEventsMap = std::map<sf::Keyboard::Key, InputsAbstraction::keyboardEvent>;
    virtual void setInputs(InputsAbstraction*) = 0;
    virtual void setInputsEvents(mouseEventsMap mouseEvents, keyboardEventsMap keyboardEvents);

    virtual void update(float dt) = 0;                  // the number of ticks since the last update
    virtual bool isDone() const;                        // if this returns true, the interface must be deleted and replaced by
    virtual up_t<AbstractGameInterface> next() = 0;     // the next interface


    protected :

    virtual void endThisLater();
    virtual InputsAbstraction* getInputs();
    virtual const InputsAbstraction* getInputs() const;


    private :

    bool m_deleteLater = false;
    InputsAbstraction* m_inputs = nullptr; // use-a
};


#endif


