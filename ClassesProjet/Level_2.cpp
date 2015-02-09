

#include "Level_2.h"
#include "Level_3.h"
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


float push_around(CarreCouleur& carre, sf::Vector2f pos, float force)
{
    pos -= carre.getPos();
    float squared_distance = sqrt(pos.x * pos.x + pos.y * pos.y);
    carre.setSpeed(500000.0f * pos * force / (squared_distance * squared_distance * squared_distance), true);
}

void Level_2::leftClick(sf::Vector2f pos)
{
    for (auto& carre_ptr : getCarres())
    {
        push_around(*carre_ptr, pos, -3);
    }
}

void Level_2::rightClick(sf::Vector2f pos)
{
    for (auto& carre_ptr : getCarres())
    {
        push_around(*carre_ptr, pos, 2);
    }
}
