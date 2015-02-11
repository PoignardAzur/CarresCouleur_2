

#include "Level_2.hpp"
#include "Level_3.hpp"
#include <cmath>

LevelBase* Level_2::getNextLevel()
{
    return new Level_3();
}

void Level_2::update(const float& dt)
{
    LevelBase::update(dt);
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
