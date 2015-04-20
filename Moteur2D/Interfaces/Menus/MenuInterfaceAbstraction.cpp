
#include "MenuInterfaceAbstraction.hpp"


void MenuInterfaceAbstraction::drawIn(DrawerAbstraction& window, float dt) const
{
    if (m_submenu)
    {
        if (m_submenu->isLayered())
        drawThisIn(window, 0);

        m_submenu->drawIn(window, dt);
    }

    else
    drawThisIn(window, dt);
}

void MenuInterfaceAbstraction::update(float dt)
{
    if (m_submenu)
    {
        if (!m_submenuLoaded)
        {
            m_submenu->load();
            m_submenuLoaded = true;
        }

        m_submenu->update(dt);

        if (m_submenu->isDone())
        {
            if (m_submenu->loadNewScreen())
            {
                setNextScreenAndClose(m_submenu->next());
            }

            m_submenu.reset();
        }
    }

    else
    updateThis(dt);
}


bool MenuInterfaceAbstraction::loadNewScreen() const
{
    return m_loadNewScreen;
}

uptrt<GameInterfaceAbstraction> MenuInterfaceAbstraction::next()
{
    return move(m_nextScreen);
}


void MenuInterfaceAbstraction::openSubmenu(uptrt<MenuInterfaceAbstraction> submenu)
{
    m_submenu = move(submenu);
}

const MenuInterfaceAbstraction* MenuInterfaceAbstraction::getSubmenu() const
{
    return m_submenu.get();
}

MenuInterfaceAbstraction* MenuInterfaceAbstraction::getSubmenu()
{
    return m_submenu.get();
}

void MenuInterfaceAbstraction::closeMenu()
{
    endThisLater();
    m_loadNewScreen = false;
}

void MenuInterfaceAbstraction::setNextScreenAndClose(uptrt<GameInterfaceAbstraction> nextScreen)
{
    endThisLater();

    m_loadNewScreen = true;
    m_nextScreen = move(nextScreen);
}

