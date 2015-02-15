
#include "MenuAbstraction.hpp"


Menu::MenuAbstraction::MenuAbstraction(bool isVertical, bool doesLoop)
{
    m_isVertical = isVertical;
    m_doesLoop = doesLoop;
}

void Menu::MenuAbstraction::select()
{
    if (selectedButton())
    selectedButton()->select();
}

void Menu::MenuAbstraction::deselect()
{
    if (selectedButton())
    selectedButton()->deselect();
}

void Menu::MenuAbstraction::press()
{
    if (selectedButton())
    selectedButton()->press();
}


void Menu::MenuAbstraction::left(bool big)
{
    if (m_isVertical)
    {
        if (selectedButton())
        selectedButton()->left(big);
    }

    else // horizontal menu
    decrement(big);
}

void Menu::MenuAbstraction::right(bool big)
{
    if (m_isVertical)
    {
        if (selectedButton())
        selectedButton()->right(big);
    }


    else // horizontal menu
    increment(big);
}

void Menu::MenuAbstraction::up(bool big)
{
    if (!m_isVertical) // horizontal menu
    {
        if (selectedButton())
        selectedButton()->up(big);
    }

    else // vertical menu
    decrement(big);
}

void Menu::MenuAbstraction::down(bool big)
{
    if (!m_isVertical) // horizontal menu
    {
        if (selectedButton())
        selectedButton()->down(big);
    }

    else // vertical menu
    increment(big);
}


Menu::ButtonAbstraction* Menu::MenuAbstraction::selectedButton()
{
    return m_buttonList[m_selectedButton];
}

const Menu::ButtonAbstraction* Menu::MenuAbstraction::selectedButton() const
{
    return const_cast<Menu::MenuAbstraction*>(this)->selectedButton();
}

void Menu::MenuAbstraction::setSelectedButton(size_t selectedButtonSlot)
{
    m_selectedButton = (m_buttonList.size() < selectedButtonSlot) ? m_buttonList.size() : selectedButtonSlot;
    updateSelected();
}

void Menu::MenuAbstraction::setButtonList(std::vector<ButtonAbstraction*> buttonList, size_t selectedButtonSlot)
{
    m_buttonList = std::move(buttonList);
    setSelectedButton(selectedButtonSlot);
}

void Menu::MenuAbstraction::addButton(ButtonAbstraction* b)
{
    if (m_selectedButton == -1)
    m_selectedButton = 0;

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
    m_selectedButton = m_buttonList.size() - 1; // if m_buttonList is empty, this is worth -1

    else
    {
        if (static_cast<size_t>(m_selectedButton + 1) < m_buttonList.size())
        m_selectedButton ++;

        else if (m_doesLoop && !m_buttonList.empty())
        m_selectedButton = 0;
    }

    updateSelected();
}

void Menu::MenuAbstraction::decrement(bool big)
{
    if (big && !m_buttonList.empty())
    m_selectedButton = 0;

    else
    {
        if (m_selectedButton > 0)
        m_selectedButton --;

        else if (m_doesLoop)
        m_selectedButton = m_buttonList.size() - 1; // if m_buttonList is empty, this is worth -1
    }

    updateSelected();
}

