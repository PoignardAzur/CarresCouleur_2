
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


void AbstractGameInterface::setUserInputs(InputsAbstraction* newInputs)
{
    m_inputs = newInputs;
}

InputsAbstraction* AbstractGameInterface::getInputs()
{
    return m_inputs;
}

const InputsAbstraction* AbstractGameInterface::getInputs() const
{
    return const_cast<AbstractGameInterface*>(this)->getInputs();
}


