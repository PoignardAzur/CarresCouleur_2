
#include "ButtonListAbstraction.hpp"


Menu::ButtonListAbstraction::ButtonListAbstraction(bool isMenuVertical, bool doesMenuLoop)
{
    m_isVertical = isMenuVertical;
    m_doesLoop = doesMenuLoop;
}

void Menu::ButtonListAbstraction::select()
{
    if (selectedButton())
    selectedButton()->select();
}

void Menu::ButtonListAbstraction::deselect()
{
    if (selectedButton())
    selectedButton()->deselect();
}

void Menu::ButtonListAbstraction::press()
{
    if (selectedButton())
    selectedButton()->press();
}


bool Menu::ButtonListAbstraction::doesLoop() const
{
    return m_doesLoop;
}

bool Menu::ButtonListAbstraction::isVertical() const
{
    return m_isVertical;
}

void Menu::ButtonListAbstraction::setLoop(bool doesMenuLoop)
{
    m_doesLoop = doesMenuLoop;
}

void Menu::ButtonListAbstraction::setVertical(bool isMenuVertical)
{
    m_isVertical = isMenuVertical;
}


void Menu::ButtonListAbstraction::left(bool big)
{
    if (m_isVertical)
    {
        if (selectedButton())
        selectedButton()->left(big);
    }

    else // horizontal menu
    decrement(big);
}

void Menu::ButtonListAbstraction::right(bool big)
{
    if (m_isVertical)
    {
        if (selectedButton())
        selectedButton()->right(big);
    }


    else // horizontal menu
    increment(big);
}

void Menu::ButtonListAbstraction::up(bool big)
{
    if (!m_isVertical) // horizontal menu
    {
        if (selectedButton())
        selectedButton()->up(big);
    }

    else // vertical menu
    decrement(big);
}

void Menu::ButtonListAbstraction::down(bool big)
{
    if (!m_isVertical) // horizontal menu
    {
        if (selectedButton())
        selectedButton()->down(big);
    }

    else // vertical menu
    increment(big);
}


Menu::ButtonAbstraction* Menu::ButtonListAbstraction::selectedButton()
{
    if (m_selectedButton != -1)
    return m_buttonPointerList[m_selectedButton];

    else
    return nullptr;
}

const Menu::ButtonAbstraction* Menu::ButtonListAbstraction::selectedButton() const
{
    return const_cast<Menu::ButtonListAbstraction*>(this)->selectedButton();
}

void Menu::ButtonListAbstraction::setSelectedButton(size_t selectedButtonSlot)
{
    m_selectedButton = (m_buttonPointerList.size() < selectedButtonSlot) ? m_buttonPointerList.size() : selectedButtonSlot;
    updateSelected();
}

void Menu::ButtonListAbstraction::setButtonPointerList(std::deque<ButtonAbstraction*> buttonList, size_t selectedButtonSlot)
{
    m_buttonPointerList = std::move(buttonList);
    setSelectedButton(selectedButtonSlot);
}

void Menu::ButtonListAbstraction::addButtonPointer(ButtonAbstraction* buttonPointer)
{
    if (m_selectedButton == -1)
    m_selectedButton = 0;

    m_buttonPointerList.push_back(buttonPointer);
    updateSelected();
}

void Menu::ButtonListAbstraction::updateSelected()
{
    for (auto button_ptr : m_buttonPointerList)
    {
        button_ptr->deselect();
    }

    if (selectedButton())
    selectedButton()->select();
}


void Menu::ButtonListAbstraction::increment(bool big)
{
    if (big)
    m_selectedButton = m_buttonPointerList.size() - 1; // if m_buttonPointerList is empty, this is worth -1

    else
    {
        if (static_cast<size_t>(m_selectedButton + 1) < m_buttonPointerList.size())
        m_selectedButton ++;

        else if (m_doesLoop && !m_buttonPointerList.empty())
        m_selectedButton = 0;
    }

    updateSelected();
}

void Menu::ButtonListAbstraction::decrement(bool big)
{
    if (big && !m_buttonPointerList.empty())
    m_selectedButton = 0;

    else
    {
        if (m_selectedButton > 0)
        m_selectedButton --;

        else if (m_doesLoop)
        m_selectedButton = m_buttonPointerList.size() - 1; // if m_buttonPointerList is empty, this is worth -1
    }

    updateSelected();
}

