

#ifndef HEADER_LEVEL_4
#define HEADER_LEVEL_4

#include "LevelBase.hpp"


class Level_4 : public LevelBase
{
    public :

    virtual void update(const float& dt);

    LevelBase* getNextLevel();
    virtual void leftClick(sf::Vector2f pos);
    virtual void rightClick(sf::Vector2f pos);


    protected :

//  VartArray<CarreCouleur> getCarres();
//  virtual std::default_random_engine& rng();

//  void increaseScore(int points);
//  int score() const;

    private :

    float m_timeBeforeNextCarre = 0;
};

#endif // HEADER_LEVEL_4
