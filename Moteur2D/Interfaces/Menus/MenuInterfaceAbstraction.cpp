
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
            m_nextLevel = m_submenu->next();
            m_submenuLoaded = false;

            if (m_nextLevel)
            endThisLater();
        }
    }

    else
    updateThis(dt);
}


uptrt<GameInterfaceAbstraction> MenuInterfaceAbstraction::next()
{
    return move(m_nextLevel);
}

void MenuInterfaceAbstraction::openSubmenu(std::unique_ptr<MenuInterfaceAbstraction> submenu)
{
    m_submenu = std::move(submenu);
}

const MenuInterfaceAbstraction* MenuInterfaceAbstraction::getSubmenu() const
{
    return m_submenu.get();
}

MenuInterfaceAbstraction* MenuInterfaceAbstraction::getSubmenu()
{
    return m_submenu.get();
}

void MenuInterfaceAbstraction::setNextLevel(uptrt<GameInterfaceAbstraction> nextLevel)
{
    m_nextLevel = move(nextLevel);
}


