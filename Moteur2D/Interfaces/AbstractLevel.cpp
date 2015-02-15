
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

void AbstractLevel::setInputs(InputsAbstraction* inputs)
{
    AbstractGameInterface::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    std::list<sf::Mouse::Button> triggerButtons = getTriggerButtons();
    std::list<sf::Keyboard::Key> triggerKeys = getTriggerKeys();

    for (const auto& button : triggerButtons)
    {
        mouseEvents[button] = [this, button](bool pressed, sf::Vector2f cursor)
        {
            if (!getPauseMenu())
            {
                trigger(button, pressed, cursor);
            }
        };
    }

    for (const auto& key : triggerKeys)
    {
        keyboardEvents[key] = [this, key](bool pressed)
        {
            if (!getPauseMenu())
            {
                trigger(key, pressed);
            }
        };
    }

    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
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
        if (!m_pauseMenuLoaded)
        {
            m_pauseMenu->load();
            m_pauseMenuLoaded = true;
        }

        m_pauseMenu->update(dt);

        if (m_pauseMenu->isDone())
        {
            m_nextInt.reset(m_pauseMenu->next().release());
            m_pauseMenu.reset();

            m_pauseMenuLoaded = false;

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

const MenuInterfaceAbstraction* AbstractLevel::getPauseMenu() const
{
    return m_pauseMenu.get();
}

MenuInterfaceAbstraction* AbstractLevel::getPauseMenu()
{
    return m_pauseMenu.get();
}

void AbstractLevel::setNextInterface(std::unique_ptr<AbstractGameInterface> nextInt)
{
    m_nextInt = move(nextInt);
}

uptrt<AbstractGameInterface> AbstractLevel::next()
{
    return move(m_nextInt);
}

