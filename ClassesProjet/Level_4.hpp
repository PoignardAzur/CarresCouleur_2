
#ifndef HEADER_LEVEL_4
#define HEADER_LEVEL_4

#include "LevelBase.hpp"


class Level_4 : public LevelBase
{
    public :

    virtual void updateThis(float dt);

    uptrt<LevelBase> getNextLevel();
    virtual void leftClick(sf::Vector2f pos);
    virtual void rightClick(sf::Vector2f pos);


    private :

    float m_timeBeforeNextCarre = 0;
};


#endif // HEADER_LEVEL_4
