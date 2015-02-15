
#ifndef GAME_INTERFACE_ABSTRACTION_HEADER
#define GAME_INTERFACE_ABSTRACTION_HEADER

#include "../Entries/InputsArray.hpp"
#include "../Graphic/DrawerAbstraction.hpp"
#include "up.hpp"


// Class that represents a chunk of the game experience (Level, Menu, Screen, etc)
class GameInterfaceAbstraction
{
    public :

    GameInterfaceAbstraction();
    virtual ~GameInterfaceAbstraction();
    virtual void load();                                // Must be called once at the start of an UPDATE PHASE before any call to update()

    virtual void setInputs(InputsAbstraction*);         // Must be overloaded to personalize Events handling
    virtual void setInputsEvents(EventsMap::MouseEventsMap mouseEvents, EventsMap::KeyboardEventsMap keyboardEvents);

    virtual void update(float dt) = 0;                  // the number of ticks since the last update
    virtual bool isDone() const;                        // if this returns true, the interface must be deleted and replaced by
    virtual uptrt<GameInterfaceAbstraction> next() = 0; // the next interface (if next() is null, then the game closes)

    virtual void drawIn(DrawerAbstraction& window, float dt) const = 0;


    protected :

    virtual void endThisLater();
    virtual InputsAbstraction* getInputs();
    virtual const InputsAbstraction* getInputs() const;


    private :

    bool m_deleteLater = false;
    InputsAbstraction* m_inputs = nullptr; // use-a

    EventsMap* m_eventsMap = nullptr; // use-a
    uptrt<EventsMap> m_unloadedEventsMap;
};


#endif // GAME_INTERFACE_ABSTRACTION_HEADER
