

#include "AbstractInputsArray.h"


std::list<sf::Mouse::Button> AbstractInputs::pressedMouseButtons() const          // array of pressed mouse buttons
{
    std::list<sf::Mouse::Button> pmb;

    for (const auto& b : mouseButtons())
    {
        if (b.second)
        pmb.push_back(b.first);
    }

    return pmb;
}

std::list<sf::Keyboard::Key>  AbstractInputs::pressedKeyboardButtons() const       // list of pressed keyboard keys
{
    std::list<sf::Keyboard::Key> pkb;

    for (const auto& k : keyboardButtons())
    {
        if (k.second)
        pkb.push_back(k.first);
    }

    return pkb;
}

bool AbstractInputs::anyMouseButtonPressed() const
{
    for (const auto& b : mouseButtons())
    {
        if (b.second)
        return true;
    }

/// default
    return false;
}

bool AbstractInputs::anyKeyPressed() const
{
    for (const auto& k : keyboardButtons())
    {
        if (k.second)
        return true;
    }

/// default
    return false;
}


const std::map<sf::Mouse::Button, bool>& AbstractInputs::mouseButtons() const
{
    return const_cast<AbstractInputs*>(this)->_mouseButtons();
}

const std::map<sf::Keyboard::Key , bool>& AbstractInputs::keyboardButtons() const
{
    return const_cast<AbstractInputs*>(this)->_keyboardButtons();
}

std::map<sf::Mouse::Button, bool>& AbstractInputs::mouseButtons()
{
    return _mouseButtons();
}

std::map<sf::Keyboard::Key , bool>& AbstractInputs::keyboardButtons()
{
    return _keyboardButtons();
}


