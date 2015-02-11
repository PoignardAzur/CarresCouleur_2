

#ifndef ABSTRACT_GAME_INTERFACE_HEADER
#define ABSTRACT_GAME_INTERFACE_HEADER

#include "../Entries/InputsArray.hpp"
#include "../Graphic/DrawerAbstraction.hpp"


template <typename In>
class AbstractGameInterface
{
    public :

    AbstractGameInterface() {}
    virtual ~AbstractGameInterface() {}

    virtual void drawIn(DrawerAbstraction& window, float dt) = 0;
    virtual void setUserInputs(InputsAbstraction*);

    virtual void update(const In& inputData) = 0;       // by default, In is the number of ticks since the last update
    virtual bool isDone() const;                        // if this returns true, the interface must be deleted and replaced by
    virtual AbstractGameInterface<In>* next() = 0;      // the next interface


    protected :

    virtual void endThisLater();
    virtual InputsAbstraction* getInputs();
    virtual const InputsAbstraction* getInputs() const;


    private :

    bool m_deleteLater = false;
    InputsAbstraction* m_inputs = nullptr; // use-a
};



template <typename In>
bool AbstractGameInterface<In>::isDone() const
{
    if (getInputs())
    return m_deleteLater || getInputs()->closeWindow();

    else
    return m_deleteLater ;
}

template <typename In>
void AbstractGameInterface<In>::endThisLater()
{
    m_deleteLater = true;
}


template <typename In>
void AbstractGameInterface<In>::setUserInputs(InputsAbstraction* newInputs)
{
    m_inputs = newInputs;
}



template <typename In>
InputsAbstraction* AbstractGameInterface<In>::getInputs()
{
    return m_inputs;
}


template <typename In>
const InputsAbstraction* AbstractGameInterface<In>::getInputs() const
{
    return const_cast<AbstractGameInterface*>(this)->getInputs();
}


#endif


