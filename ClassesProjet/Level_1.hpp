

#ifndef HEADER_LEVEL_1
#define HEADER_LEVEL_1

#include "LevelBase.hpp"


class Level_1 : public LevelBase
{
    public :

    uptrt<LevelBase> getNextLevel();

    void leftClick(sf::Vector2f pos);
    void rightClick(sf::Vector2f pos);
};

#endif // HEADER_LEVEL_1
