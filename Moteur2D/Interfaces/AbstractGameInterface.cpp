
#include "AbstractGameInterface.hpp"


AbstractGameInterface::AbstractGameInterface()
{

}

AbstractGameInterface::~AbstractGameInterface()
{

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

void AbstractGameInterface::setInputsEvents(mouseEventsMap mouseEvents, keyboardEventsMap keyboardEvents)
{
    m_inputs->setMouseButtonEvents(std::move(mouseEvents));
    m_inputs->setKeyboardButtonEvents(std::move(keyboardEvents));
}

InputsAbstraction* AbstractGameInterface::getInputs()
{
    return m_inputs;
}

const InputsAbstraction* AbstractGameInterface::getInputs() const
{
    return const_cast<AbstractGameInterface*>(this)->getInputs();
}


