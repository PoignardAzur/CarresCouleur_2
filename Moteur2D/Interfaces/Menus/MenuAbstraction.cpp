

#include "MenuAbstraction.hpp"

Menu::MenuAbstraction::MenuAbstraction(bool isVertical, bool doesLoop)
{
    m_isVertical = isVertical;
    m_doesLoop = doesLoop;
}

void Menu::MenuAbstraction::select()
{
    selectedButton()->select();
}

void Menu::MenuAbstraction::deselect()
{
    selectedButton()->deselect();
}

void Menu::MenuAbstraction::press()
{
    selectedButton()->press();
}


void Menu::MenuAbstraction::left(bool big)
{
    if (m_isVertical)
    selectedButton()->left(big);

    else
    decrement(big);
}

void Menu::MenuAbstraction::right(bool big)
{
    if (m_isVertical)
    selectedButton()->right(big);

    else
    increment(big);
}

void Menu::MenuAbstraction::up(bool big)
{
    if (!m_isVertical)
    selectedButton()->up(big);

    else
    decrement(big);
}

void Menu::MenuAbstraction::down(bool big)
{
    if (!m_isVertical)
    selectedButton()->down(big);

    else
    increment(big);
}


Menu::ButtonAbstraction* Menu::MenuAbstraction::selectedButton()
{
    return m_buttonList[m_selectedButton];
}

const Menu::ButtonAbstraction* Menu::MenuAbstraction::selectedButton() const
{
    return m_buttonList[m_selectedButton];
}

void Menu::MenuAbstraction::setButtonList(std::vector<ButtonAbstraction*> buttonList, size_t selectedButtonSlot)
{
    m_buttonList = std::move(buttonList);
    m_selectedButton = (m_buttonList.size() < selectedButtonSlot) ? m_buttonList.size() : selectedButtonSlot;

    updateSelected();
}

void Menu::MenuAbstraction::addButton(ButtonAbstraction* b)
{
    m_buttonList.push_back(b);
    updateSelected();
}

void Menu::MenuAbstraction::updateSelected()
{
    for (auto button_ptr : m_buttonList)
    {
        button_ptr->deselect();
    }

    if (selectedButton())
    selectedButton()->select();
}


void Menu::MenuAbstraction::increment(bool big)
{
    if (big)
    m_selectedButton = m_buttonList.size() - 1;

    else
    {
        if (m_selectedButton + 1 < m_buttonList.size())
        m_selectedButton ++;

        else if (m_doesLoop)
        m_selectedButton = 0;
    }

    updateSelected();
}

void Menu::MenuAbstraction::decrement(bool big)
{
    if (big)
    m_selectedButton = 0;

    else
    {
        if (m_selectedButton > 0)
        m_selectedButton --;

        else if (m_doesLoop)
        m_selectedButton = m_buttonList.size();
    }

    updateSelected();
}

