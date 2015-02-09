

#include "AbstractMenu.h"

Menu::AbstractMenu::AbstractMenu(bool isVertical, bool doesLoop)
{
    m_isVertical = isVertical;
    m_doesLoop = doesLoop;
}

void Menu::AbstractMenu::select()
{
    selectedButton()->select();
}

void Menu::AbstractMenu::deselect()
{
    selectedButton()->deselect();
}

void Menu::AbstractMenu::press()
{
    selectedButton()->press();
}


void Menu::AbstractMenu::left(bool big)
{
    if (m_isVertical)
    selectedButton()->left(big);

    else
    decrement(big);
}

void Menu::AbstractMenu::right(bool big)
{
    if (m_isVertical)
    selectedButton()->right(big);

    else
    increment(big);
}

void Menu::AbstractMenu::up(bool big)
{
    if (!m_isVertical)
    selectedButton()->up(big);

    else
    decrement(big);
}

void Menu::AbstractMenu::down(bool big)
{
    if (!m_isVertical)
    selectedButton()->down(big);

    else
    increment(big);
}


Menu::AbstractButton* Menu::AbstractMenu::selectedButton()
{
    return m_buttonList[m_selectedButton];
}

const Menu::AbstractButton* Menu::AbstractMenu::selectedButton() const
{
    return m_buttonList[m_selectedButton];
}

void Menu::AbstractMenu::setButtonList(std::vector<AbstractButton*> buttonList, size_t selectedButtonSlot)
{
    m_buttonList = std::move(buttonList);
    m_selectedButton = (m_buttonList.size() < selectedButtonSlot) ? m_buttonList.size() : selectedButtonSlot;

    updateSelected();
}

void Menu::AbstractMenu::addButton(AbstractButton* b)
{
    m_buttonList.push_back(b);
    updateSelected();
}

void Menu::AbstractMenu::updateSelected()
{
    for (auto button_ptr : m_buttonList)
    {
        button_ptr->deselect();
    }

    if (selectedButton())
    selectedButton()->select();
}


void Menu::AbstractMenu::increment(bool big)
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

void Menu::AbstractMenu::decrement(bool big)
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

