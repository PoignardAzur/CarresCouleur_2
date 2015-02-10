

#ifndef HEADER_LEVEL_3
#define HEADER_LEVEL_3

#include "LevelBase.hpp"


class Level_3 : public LevelBase
{
    public :

    Level_3();

    LevelBase* getNextLevel();
    void drawIn(AbstractDrawer& window, float dt);
    virtual void update(const float& dt);

    void generateCarre();

    void leftClick(sf::Vector2f pos);
    void rightClick(sf::Vector2f pos);


    protected :

//  VartArray<CarreCouleur> getCarres();
//  virtual std::default_random_engine& rng();

//  void increaseScore(int points);
//  int score() const;

    private :

    CarreCouleur m_carreGris;
};

#endif // HEADER_LEVEL_3
