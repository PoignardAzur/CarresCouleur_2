
#include "AbstractLevel.hpp"


AbstractLevel::AbstractLevel(unsigned int seed) : m_randomGenerator(seed)
{

}

AbstractLevel::AbstractLevel(std::seed_seq& seed) : m_randomGenerator(seed)
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

AbstractLevel::~AbstractLevel()
{

}


std_rng& AbstractLevel::rng()
{
    return m_randomGenerator;
}


void AbstractLevel::drawIn(DrawerAbstraction& window, float dt)
{
    if (m_pauseMenu)
    {
        if (m_pauseMenu->isLayered())
        drawThisIn(window, 0);

        m_pauseMenu->drawIn(window, dt);
    }

    else
    drawThisIn(window, dt);
}

void AbstractLevel::update(float dt)
{
    if (m_pauseMenu)
    {
        m_pauseMenu->update(dt);

        if (m_pauseMenu->isDone())
        {
            delete m_nextInt;
            m_nextInt = m_pauseMenu->next();
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
    m_nextInt = nextInt.release();
}

AbstractGameInterface* AbstractLevel::next()
{
    return m_nextInt;
}

