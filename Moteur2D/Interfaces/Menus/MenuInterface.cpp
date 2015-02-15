
#include "MenuInterface.hpp"


Menu::MenuInterface::MenuInterface(bool isVertical, bool doesLoop) : MenuAbstraction(isVertical, doesLoop)
{

}

void Menu::MenuInterface::setInputs(InputsAbstraction* inputs)
{
    GameInterfaceAbstraction::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    keyboardEvents[sf::Keyboard::Up] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            up(false);
        }
    };

    keyboardEvents[sf::Keyboard::Down] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            down(false);
        }
    };

    keyboardEvents[sf::Keyboard::Left] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            left(false);
        }
    };

    keyboardEvents[sf::Keyboard::Right] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            right(false);
        }
    };

    keyboardEvents[sf::Keyboard::Space] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            press();
        }
    };

    keyboardEvents[sf::Keyboard::Return] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            press();
        }
    };

    keyboardEvents[sf::Keyboard::Escape] = [this](bool pressed)
    {
        if (pressed && !getSubmenu())
        {
            escape();
        }
    };

    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
}


void Menu::MenuInterface::updateThis(float dt)
{
    (void) dt;
}


