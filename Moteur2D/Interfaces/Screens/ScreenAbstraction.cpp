
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

void ScreenAbstraction::setInputs(InputsAbstraction* newInputs)
{
    m_inputs = newInputs;
}

void ScreenAbstraction::setInputsEvents(EventsMap::MouseEventsMap mouseEvents, EventsMap::KeyboardEventsMap keyboardEvents)
{
    m_unloadedEventsMap.reset(new EventsMap( move(mouseEvents), move(keyboardEvents) ));
}


bool ScreenAbstraction::isDone() const
{
    return m_deleteLater || (getInputs() && getInputs()->closeWindow());
}

uptrt<ScreenAbstraction> ScreenAbstraction::getNextScreen()
{
    return move(m_nextScreen);
}


void ScreenAbstraction::closeLater(ScreenPointer nextScreen)
{
    m_deleteLater = true;
    m_nextScreen = move(nextScreen);
}


InputsAbstraction* ScreenAbstraction::getInputs()
{
    return m_inputs;
}

const InputsAbstraction* ScreenAbstraction::getInputs() const
{
    return const_cast<ScreenAbstraction*>(this)->getInputs();
}

