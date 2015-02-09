

#include "Level_3.h"
#include "Level_4.h"


Level_3::Level_3() : m_carreGris(sf::Color(128, 128, 128), DEFAULT_CARRE_SIZE * 3)
{

}

LevelBase* Level_3::getNextLevel()
{
    return new Level_4();
}

void Level_3::drawIn(AbstractDrawer& window, float dt)
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
    for (auto& carre_ptr : getCarres())
    {
        if (carre_ptr->recycle(m_carreGris.getHitbox(pos), false))
        increaseScore(20);
    }
}

void Level_3::rightClick(sf::Vector2f pos)
{
    for (auto& carre_ptr : getCarres())
    {
        if (carre_ptr->getHitbox(carre_ptr->getPos()).intersects(m_carreGris.getHitbox(pos)))
        carre_ptr->randomizeSpeed(rng());
    }
}
