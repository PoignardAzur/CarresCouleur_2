
#ifndef GAME_SCREEN_ABSTRACTION_HEADER
#define GAME_SCREEN_ABSTRACTION_HEADER

#include "../../Entries/InputsArray.hpp"
#include "../../Graphic/DrawerAbstraction.hpp"
#include "up.hpp"


/*
Class that represents a chunk of the game experience (Level, Menu, Screen, etc)
POINTER SAFETY : 'update()' must not be called after 'm_inputs' is deleted
'load()' must be called after 'setInputs()' and before 'update()' or any
method with repercussions outside of the class
*/
class ScreenAbstraction
{
    public :

    ScreenAbstraction();
    virtual ~ScreenAbstraction();
    virtual void load();                                // Must be called once at the start of an UPDATE PHASE before any call to update()

    virtual void setInputs(InputsAbstraction*);         // Must be overloaded to personalize Events handling
    virtual void setInputsEvents(EventsMap::MouseEventsMap mouseEvents, EventsMap::KeyboardEventsMap keyboardEvents);

    using ScreenPointer = uptrt<ScreenAbstraction>;

    virtual void update(float dt) = 0;                  // the number of ticks since the last update
    virtual bool isDone() const;                        // if this returns true, the interface must be deleted and replaced by
    virtual ScreenPointer getNextScreen() = 0;          // the next interface (if next() is null, then the game closes)

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


#endif // GAME_SCREEN_ABSTRACTION_HEADER
