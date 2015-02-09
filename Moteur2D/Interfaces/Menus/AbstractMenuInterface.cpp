
#include "AbstractMenuInterface.h"


void AbstractMenuInterface::drawIn(AbstractDrawer& window, float dt)
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

void AbstractMenuInterface::update(const float& dt)
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


AbstractGameInterface<float>* AbstractMenuInterface::next()
{
    return m_nextLevel;
}

void AbstractMenuInterface::openSubmenu(std::unique_ptr<AbstractMenuInterface> submenu)
{
    m_submenu = std::move(submenu);
}

void AbstractMenuInterface::setNextLevel(AbstractGameInterface<float>* nextLevel)
{
    m_nextLevel = nextLevel;
}


