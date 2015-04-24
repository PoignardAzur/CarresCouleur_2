
#include "ScreenAbstraction.hpp"


ScreenAbstraction::ScreenAbstraction()
{

}

ScreenAbstraction::~ScreenAbstraction()
{
    if (m_eventsMap)
    m_eventsMap->remove();
}

void ScreenAbstraction::load()
{
    m_eventsMap = m_unloadedEventsMap.get();

    if (m_eventsMap)
    m_inputs->addEventsMap(move(m_unloadedEventsMap));
}

bool ScreenAbstraction::isDone() const
{
    if (getInputs())
    return m_deleteLater || getInputs()->closeWindow();

    else
    return m_deleteLater ;
}

void ScreenAbstraction::endThisLater()
{
    m_deleteLater = true;
}


void ScreenAbstraction::setInputs(InputsAbstraction* newInputs)
{
    m_inputs = newInputs;
}

void ScreenAbstraction::setInputsEvents(EventsMap::MouseEventsMap mouseEvents, EventsMap::KeyboardEventsMap keyboardEvents)
{
    m_unloadedEventsMap.reset(new EventsMap( move(mouseEvents), move(keyboardEvents) ));
}

InputsAbstraction* ScreenAbstraction::getInputs()
{
    return m_inputs;
}

const InputsAbstraction* ScreenAbstraction::getInputs() const
{
    return const_cast<ScreenAbstraction*>(this)->getInputs();
}


