
#include "GameInterfaceAbstraction.hpp"


GameInterfaceAbstraction::GameInterfaceAbstraction()
{

}

GameInterfaceAbstraction::~GameInterfaceAbstraction()
{
    if (m_eventsMap)
    m_eventsMap->remove();
}

void GameInterfaceAbstraction::load()
{
    m_eventsMap = m_unloadedEventsMap.get();

    if (m_eventsMap)
    m_inputs->addEventsMap(move(m_unloadedEventsMap));
}

bool GameInterfaceAbstraction::isDone() const
{
    if (getInputs())
    return m_deleteLater || getInputs()->closeWindow();

    else
    return m_deleteLater ;
}

void GameInterfaceAbstraction::endThisLater()
{
    m_deleteLater = true;
}


void GameInterfaceAbstraction::setInputs(InputsAbstraction* newInputs)
{
    m_inputs = newInputs;
}

void GameInterfaceAbstraction::setInputsEvents(EventsMap::MouseEventsMap mouseEvents, EventsMap::KeyboardEventsMap keyboardEvents)
{
    m_unloadedEventsMap.reset(new EventsMap( move(mouseEvents), move(keyboardEvents) ));
}

InputsAbstraction* GameInterfaceAbstraction::getInputs()
{
    return m_inputs;
}

const InputsAbstraction* GameInterfaceAbstraction::getInputs() const
{
    return const_cast<GameInterfaceAbstraction*>(this)->getInputs();
}


