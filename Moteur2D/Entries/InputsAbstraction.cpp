

#include "InputsAbstraction.hpp"


std::list<sf::Mouse::Button> InputsAbstraction::getPressedMouseButtons() const          // array of pressed mouse buttons
{
    std::list<sf::Mouse::Button> pmb;

    for (const auto& b : getMouseButtons())
    {
        if (b.second)
        pmb.push_back(b.first);
    }

    return pmb;
}

std::list<sf::Keyboard::Key> InputsAbstraction::getPressedKeyboardButtons() const       // list of pressed keyboard keys
{
    std::list<sf::Keyboard::Key> pkb;

    for (const auto& k : getKeyboardButtons())
    {
        if (k.second)
        pkb.push_back(k.first);
    }

    return pkb;
}

bool InputsAbstraction::isAnyMouseButtonPressed() const
{
    for (const auto& b : getMouseButtons())
    {
        if (b.second)
        return true;
    }

//  default
    return false;
}

bool InputsAbstraction::isAnyKeyPressed() const
{
    for (const auto& k : getKeyboardButtons())
    {
        if (k.second)
        return true;
    }

//  default
    return false;
}


const std::map<sf::Mouse::Button, bool>& InputsAbstraction::getMouseButtons() const
{
    return const_cast<InputsAbstraction*>(this)->_getMouseButtons();
}

const std::map<sf::Keyboard::Key , bool>& InputsAbstraction::getKeyboardButtons() const
{
    return const_cast<InputsAbstraction*>(this)->_getKeyboardButtons();
}

std::map<sf::Mouse::Button, bool>& InputsAbstraction::getMouseButtons()
{
    return _getMouseButtons();
}

std::map<sf::Keyboard::Key , bool>& InputsAbstraction::getKeyboardButtons()
{
    return _getKeyboardButtons();
}


