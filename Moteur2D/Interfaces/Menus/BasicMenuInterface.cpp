
#include "BasicMenuInterface.hpp"


std::function<void(bool)> BasicMenuInterface::buttonPressedFunction(std::function<void(void)> f)
{
    return [this, f](bool pressed)
    {
        // This is not called for a button release, if a submenu is open,
        // nor when the Menu has already been flagged for deletion
        if (pressed && !getSubmenu() && !isDone())
        {
            f();
        }
    };
}

void BasicMenuInterface::setInputs(InputsAbstraction* inputs)
{
    ScreenAbstraction::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    keyboardEvents[sf::Keyboard::Up] =      buttonPressedFunction( [this]() { buttonList().up(false); } );
    keyboardEvents[sf::Keyboard::Down] =    buttonPressedFunction( [this]() { buttonList().down(false); } );
    keyboardEvents[sf::Keyboard::Left] =    buttonPressedFunction( [this]() { buttonList().left(false); } );
    keyboardEvents[sf::Keyboard::Right] =   buttonPressedFunction( [this]() { buttonList().right(false); } );
    keyboardEvents[sf::Keyboard::Space] =   buttonPressedFunction( [this]() { buttonList().press(); } );
    keyboardEvents[sf::Keyboard::Return] =  buttonPressedFunction( [this]() { buttonList().press(); } );
    keyboardEvents[sf::Keyboard::Escape] =  buttonPressedFunction( [this]() { escape(); } );

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

