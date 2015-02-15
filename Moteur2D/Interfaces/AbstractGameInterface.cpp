
#include "AbstractGameInterface.hpp"


AbstractGameInterface::AbstractGameInterface()
{

}

AbstractGameInterface::~AbstractGameInterface()
{
    if (m_eventsMap)
    m_eventsMap->remove();
}

void AbstractGameInterface::load()
{
    m_eventsMap = m_unloadedEventsMap.get();

    if (m_eventsMap)
    m_inputs->addEventsMap(move(m_unloadedEventsMap));
}

bool AbstractGameInterface::isDone() const
{
    if (getInputs())
    return m_deleteLater || getInputs()->closeWindow();

    else
    return m_deleteLater ;
}

void AbstractGameInterface::endThisLater()
{
    m_deleteLater = true;
}


void AbstractGameInterface::setInputs(InputsAbstraction* newInputs)
{
    m_inputs = newInputs;
}

void AbstractGameInterface::setInputsEvents(EventsMap::MouseEventsMap mouseEvents, EventsMap::KeyboardEventsMap keyboardEvents)
{
    m_unloadedEventsMap.reset(new EventsMap( move(mouseEvents), move(keyboardEvents) ));
}

InputsAbstraction* AbstractGameInterface::getInputs()
{
    return m_inputs;
}

const InputsAbstraction* AbstractGameInterface::getInputs() const
{
    return const_cast<AbstractGameInterface*>(this)->getInputs();
}


