

#include "Level_3.hpp"
#include "Level_4.hpp"


Level_3::Level_3() : m_carreGris(sf::Color(128, 128, 128), DEFAULT_CARRE_SIZE * 3)
{

}

LevelBase* Level_3::getNextLevel()
{
    return new Level_4();
}

void Level_3::drawIn(DrawerAbstraction& window, float dt)
{
    m_carreGris.drawIn(getInputs()->cursor(),window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), dt);
    LevelBase::drawIn(window, dt);
}

void Level_3::update(const float& dt)
{
    LevelBase::update(dt);
    generateCarreStream(dt);
}


void Level_3::leftClick(sf::Vector2f pos)
{
    for (auto& placedCarre : getCarres())
    {
        if (placedCarre.get().recycle(placedCarre.getPos(), m_carreGris.getHitbox(pos), false))
        increaseScore(20);
    }
}

void Level_3::rightClick(sf::Vector2f pos)
{
    for (auto& placedCarre : getCarres())
    {
        if (placedCarre.get().getHitbox(placedCarre.getPos()).intersects(m_carreGris.getHitbox(pos)))
        placedCarre.get().randomizeSpeed(rng());
    }
}
