

#include "Level_2.hpp"
#include "Level_3.hpp"
#include <cmath>

up_t<LevelBase> Level_2::getNextLevel()
{
    return up(new Level_3());
}

void Level_2::updateThis(float dt)
{
    LevelBase::updateThis(dt);
    generateCarreStream(dt);
}


void pushAround(Placed<CarreCouleur>& carre, sf::Vector2f pos, float force)
{
    pos -= carre.getPos();
    float squared_distance = sqrt(pos.x * pos.x + pos.y * pos.y);
    carre.get().setSpeed(500000.0f * pos * force / (squared_distance * squared_distance * squared_distance), true);
}

void Level_2::leftClick(sf::Vector2f pos)
{
    for (auto& placedCarre : getCarres())
    {
        pushAround(placedCarre, pos, -3);
    }
}

void Level_2::rightClick(sf::Vector2f pos)
{
    for (auto& placedCarre : getCarres())
    {
        pushAround(placedCarre, pos, 2);
    }
}

