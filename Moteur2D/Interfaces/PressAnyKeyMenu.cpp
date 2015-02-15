
#include "PressAnyKeyMenu.hpp"


void PressAnyKeyMenu::update(float dt)
{
    if (GameInterfaceAbstraction::getInputs()->isAnyKeyPressed())
    GameInterfaceAbstraction::endThisLater();

    (void) dt;
}

void PressAnyKeyMenu::setNext(uptrt<GameInterfaceAbstraction> nextInterface)
{
    GameInterfaceAbstraction* nextInterface_ = nextInterface.release();

    setNext
    (
        [=](void)
        {
            return uptr(nextInterface_);
        }
    );
}

void PressAnyKeyMenu::setNext(std::function<uptrt<GameInterfaceAbstraction>(void)> nextInterface)
{
    m_nextInterface = nextInterface;
}

uptrt<GameInterfaceAbstraction> PressAnyKeyMenu::next()
{
    return m_nextInterface();
}

