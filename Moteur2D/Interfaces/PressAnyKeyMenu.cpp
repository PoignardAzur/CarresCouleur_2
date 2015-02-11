
#include "PressAnyKeyMenu.hpp"


void PressAnyKeyMenu::update(float dt)
{
    if (AbstractGameInterface::getInputs()->isAnyKeyPressed())
    AbstractGameInterface::endThisLater();

    (void) dt;
}

void PressAnyKeyMenu::setNext(AbstractGameInterface* nextInterface)
{
    setNext
    (
        [=](void)
        {
            return nextInterface;
        }
    );
}

void PressAnyKeyMenu::setNext(std::function<AbstractGameInterface*(void)> nextInterface)
{
    m_nextInterface = nextInterface;
}

AbstractGameInterface* PressAnyKeyMenu::next()
{
    return m_nextInterface();
}

