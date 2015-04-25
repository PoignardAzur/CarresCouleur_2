
#include "PressKeyToContinue.hpp"


void PressKeyToContinue::setInputs(InputsAbstraction* inputs)
{
    ScreenAbstraction::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    auto keys = getKeysToContinue();

    for (auto key : keys)
    {
        keyboardEvents[key] = [this](bool pressed)
        {
            if (pressed)
            closeLater(loadNextScreen());
        };
    }

    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
}

std::set<sf::Keyboard::Key> PressKeyToContinue::getKeysToContinue()
{
    return std::set<sf::Keyboard::Key>();
}


void PressKeyToContinue::update(float dt)
{
    (void) dt;
}

