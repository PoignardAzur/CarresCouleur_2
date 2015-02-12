
#include "AbstractLevel.hpp"


AbstractLevel::AbstractLevel(unsigned int seed) : m_randomGenerator(seed)
{

}

AbstractLevel::AbstractLevel(std::seed_seq& seed) : m_randomGenerator(seed)
{

}

AbstractLevel::~AbstractLevel()
{

}

void AbstractLevel::setSeed(unsigned int seed)
{
    m_randomGenerator.seed(seed);
}

void AbstractLevel::setSeed(std::seed_seq& seed)
{
    m_randomGenerator.seed(seed);
}


std_rng& AbstractLevel::rng()
{
    return m_randomGenerator;
}


void AbstractLevel::drawIn(DrawerAbstraction& window, float dt) const
{
    if (!m_pauseMenu || m_pauseMenu->isLayered())
    {
        drawThisIn(window, dt);
        drawHUDIn(window, dt);
    }

    if (m_pauseMenu)
    m_pauseMenu->drawIn(window, dt);
}

void AbstractLevel::update(float dt)
{
    if (m_pauseMenu)
    {
        m_pauseMenu->update(dt);

        if (m_pauseMenu->isDone())
        {
            m_nextInt.reset(m_pauseMenu->next().release());
            m_pauseMenu.reset();

            if (m_nextInt)
            AbstractGameInterface::endThisLater();
        }
    }

    else
    updateThis(dt);
}


void AbstractLevel::pauseLevel(std::unique_ptr<MenuInterfaceAbstraction> pauseMenu)
{
    m_pauseMenu = std::move(pauseMenu);
}

void AbstractLevel::setNextInterface(std::unique_ptr<AbstractGameInterface> nextInt)
{
    m_nextInt = mv(nextInt);
}

up_t<AbstractGameInterface> AbstractLevel::next()
{
    return mv(m_nextInt);
}

