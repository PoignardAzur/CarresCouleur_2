
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
    ScreenAbstraction::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    std::list<sf::Mouse::Button> triggerButtons = getTriggerButtons();
    std::list<sf::Keyboard::Key> triggerKeys = getTriggerKeys();

    for (const auto& button : triggerButtons)
    {
        mouseEvents[button] = [this, button](bool pressed, sf::Vector2f cursor)
        {
            if (!getPauseMenu() && !isDone())
            {
                trigger(button, pressed, cursor);
            }
        };
    }

    for (const auto& key : triggerKeys)
    {
        keyboardEvents[key] = [this, key](bool pressed)
        {
            if (!getPauseMenu() && !isDone())
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
            if (m_pauseMenu->loadNewScreen())
            {
                m_nextScreen = m_pauseMenu->getNextScreen();
                ScreenAbstraction::endThisLater();
            }

            m_pauseMenu.reset();
            m_pauseMenuLoaded = false;
        }
    }

    else
    updateThis(dt);
}


void Level::pauseLevel(uptrt<MenuInterfaceAbstraction> pauseMenu)
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

void Level::setNextInterface(uptrt<ScreenAbstraction> nextInt)
{
    m_nextScreen = move(nextInt);
}

uptrt<ScreenAbstraction> Level::getNextScreen()
{
    return move(m_nextScreen);
}

