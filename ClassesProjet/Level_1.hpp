

#ifndef HEADER_LEVEL_1
#define HEADER_LEVEL_1

#include "LevelBase.h"


class Level_1 : public LevelBase
{
    public :

    LevelBase* getNextLevel();

    void leftClick(sf::Vector2f pos);
    void rightClick(sf::Vector2f pos);
};

#endif // HEADER_LEVEL_1
