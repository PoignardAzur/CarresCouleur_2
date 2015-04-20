
#include "MenuInterface.hpp"


void BasicMenuInterface::setInputs(InputsAbstraction* inputs)
{
    GameInterfaceAbstraction::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    keyboardEvents[sf::Keyboard::Up] = [this](bool pressed)
    {
        // None of those methods are called for a button release, if a submenu is open,
        // or when the Menu has already been flagged for deletion
        if (pressed && !getSubmenu() && !isDone())
        {
            buttonList().up(false);
        }
    };

    keyboardEvents[sf::Keyboard::Down] = [this](bool pressed)
    {
        if (pressed && !getSubmenu() && !isDone())
        {
            buttonList().down(false);
        }
    };

    keyboardEvents[sf::Keyboard::Left] = [this](bool pressed)
    {
        if (pressed && !getSubmenu() && !isDone())
        {
            buttonList().left(false);
        }
    };

    keyboardEvents[sf::Keyboard::Right] = [this](bool pressed)
    {
        if (pressed && !getSubmenu() && !isDone())
        {
            buttonList().right(false);
        }
    };

    keyboardEvents[sf::Keyboard::Space] = [this](bool pressed)
    {
        if (pressed && !getSubmenu() && !isDone())
        {
            buttonList().press();
        }
    };

    keyboardEvents[sf::Keyboard::Return] = [this](bool pressed)
    {
        if (pressed && !getSubmenu() && !isDone())
        {
            buttonList().press();
        }
    };

    keyboardEvents[sf::Keyboard::Escape] = [this](bool pressed)
    {
        if (pressed && !getSubmenu() && !isDone())
        {
            escape();
        }
    };

    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
}


void BasicMenuInterface::escape()
{
    closeMenu();
}


void BasicMenuInterface::updateThis(float dt)
{
    (void) dt;
}

