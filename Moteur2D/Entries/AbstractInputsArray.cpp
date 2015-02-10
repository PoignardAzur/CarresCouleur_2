

#include "AbstractInputsArray.hpp"


std::list<sf::Mouse::Button> AbstractInputs::getPressedMouseButtons() const          // array of pressed mouse buttons
{
    std::list<sf::Mouse::Button> pmb;

    for (const auto& b : getMouseButtons())
    {
        if (b.second)
        pmb.push_back(b.first);
    }

    return pmb;
}

std::list<sf::Keyboard::Key> AbstractInputs::getPressedKeyboardButtons() const       // list of pressed keyboard keys
{
    std::list<sf::Keyboard::Key> pkb;

    for (const auto& k : getKeyboardButtons())
    {
        if (k.second)
        pkb.push_back(k.first);
    }

    return pkb;
}

bool AbstractInputs::isAnyMouseButtonPressed() const
{
    for (const auto& b : getMouseButtons())
    {
        if (b.second)
        return true;
    }

//  default
    return false;
}

bool AbstractInputs::isAnyKeyPressed() const
{
    for (const auto& k : getKeyboardButtons())
    {
        if (k.second)
        return true;
    }

//  default
    return false;
}


const std::map<sf::Mouse::Button, bool>& AbstractInputs::getMouseButtons() const
{
    return const_cast<AbstractInputs*>(this)->_getMouseButtons();
}

const std::map<sf::Keyboard::Key , bool>& AbstractInputs::getKeyboardButtons() const
{
    return const_cast<AbstractInputs*>(this)->_getKeyboardButtons();
}

std::map<sf::Mouse::Button, bool>& AbstractInputs::getMouseButtons()
{
    return _getMouseButtons();
}

std::map<sf::Keyboard::Key , bool>& AbstractInputs::getKeyboardButtons()
{
    return _getKeyboardButtons();
}


