
#include "Level.hpp"


Level::Level(unsigned int seed) : m_randomGenerator(seed)
{

}

Level::Level(std::seed_seq& seed) : m_randomGenerator(seed)
{

}

Level::~Level()
{

}

void Level::setSeed(unsigned int seed)
{
    m_randomGenerator.seed(seed);
}

void Level::setSeed(std::seed_seq& seed)
{
    m_randomGenerator.seed(seed);
}

void Level::setInputs(InputsAbstraction* inputs)
{
    GameInterfaceAbstraction::setInputs(inputs);

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


std_rng& Level::rng()
{
    return m_randomGenerator;
}


void Level::drawIn(DrawerAbstraction& window, float dt) const
{
    if (!m_pauseMenu || m_pauseMenu->isLayered())
    {
        drawThisIn(window, dt);
        drawHUDIn(window, dt);
    }

    if (m_pauseMenu)
    m_pauseMenu->drawIn(window, dt);
}

void Level::update(float dt)
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
            GameInterfaceAbstraction::endThisLater();
        }
    }

    else
    updateThis(dt);
}


void Level::pauseLevel(std::unique_ptr<MenuInterfaceAbstraction> pauseMenu)
{
    m_pauseMenu = std::move(pauseMenu);
}

const MenuInterfaceAbstraction* Level::getPauseMenu() const
{
    return m_pauseMenu.get();
}

MenuInterfaceAbstraction* Level::getPauseMenu()
{
    return m_pauseMenu.get();
}

void Level::setNextInterface(std::unique_ptr<GameInterfaceAbstraction> nextInt)
{
    m_nextInt = move(nextInt);
}

uptrt<GameInterfaceAbstraction> Level::next()
{
    return move(m_nextInt);
}

