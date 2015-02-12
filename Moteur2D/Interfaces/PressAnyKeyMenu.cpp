
#include "PressAnyKeyMenu.hpp"


void PressAnyKeyMenu::setInputs(InputsAbstraction* inputs)
{
    AbstractGameInterface::setInputs(inputs);

    std::map<sf::Mouse::Button, InputsAbstraction::mouseEvent> mouseEvents;
    std::map<sf::Keyboard::Key, InputsAbstraction::keyboardEvent> keyboardEvents;
    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
}

void PressAnyKeyMenu::update(float dt)
{
    if (AbstractGameInterface::getInputs()->isAnyKeyPressed())
    AbstractGameInterface::endThisLater();

    (void) dt;
}

void PressAnyKeyMenu::setNext(up_t<AbstractGameInterface> nextInterface)
{
    AbstractGameInterface* nextInterface_ = nextInterface.release();

    setNext
    (
        [=](void)
        {
            return up(nextInterface_);
        }
    );
}

void PressAnyKeyMenu::setNext(std::function<up_t<AbstractGameInterface>(void)> nextInterface)
{
    m_nextInterface = nextInterface;
}

up_t<AbstractGameInterface> PressAnyKeyMenu::next()
{
    return m_nextInterface();
}

