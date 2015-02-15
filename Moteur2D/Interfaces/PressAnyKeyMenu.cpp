
#include "PressAnyKeyMenu.hpp"


void PressAnyKeyMenu::update(float dt)
{
    if (AbstractGameInterface::getInputs()->isAnyKeyPressed())
    AbstractGameInterface::endThisLater();

    (void) dt;
}

void PressAnyKeyMenu::setNext(uptrt<AbstractGameInterface> nextInterface)
{
    AbstractGameInterface* nextInterface_ = nextInterface.release();

    setNext
    (
        [=](void)
        {
            return uptr(nextInterface_);
        }
    );
}

void PressAnyKeyMenu::setNext(std::function<uptrt<AbstractGameInterface>(void)> nextInterface)
{
    m_nextInterface = nextInterface;
}

uptrt<AbstractGameInterface> PressAnyKeyMenu::next()
{
    return m_nextInterface();
}

