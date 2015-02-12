
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
        m_submenu->update(dt);

        if (m_submenu->isDone())
        m_nextLevel = m_submenu->next();

        if (m_nextLevel)
        endThisLater();
    }

    else
    updateThis(dt);
}


up_t<AbstractGameInterface> MenuInterfaceAbstraction::next()
{
    return mv(m_nextLevel);
}

void MenuInterfaceAbstraction::openSubmenu(std::unique_ptr<MenuInterfaceAbstraction> submenu)
{
    m_submenu = std::move(submenu);
}

void MenuInterfaceAbstraction::setNextLevel(up_t<AbstractGameInterface> nextLevel)
{
    m_nextLevel = mv(nextLevel);
}


