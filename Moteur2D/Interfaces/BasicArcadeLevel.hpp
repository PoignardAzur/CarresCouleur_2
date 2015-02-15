
#ifndef BASIC_ARCADE_LEVEL_HEADER
#define BASIC_ARCADE_LEVEL_HEADER

#include "Level.hpp"
#include "../Timer.hpp"


// Basic implementation of Level, with lives, a score and a Game Over event
class BasicArcadeLevel : public Level
{
    public :

    BasicArcadeLevel(unsigned int seed = epoch_to_now().count());
    BasicArcadeLevel(std::seed_seq& seed);
    virtual ~BasicArcadeLevel();


    protected :

    bool isGameOver() const;
    virtual bool isPlayerAlive() const = 0;
    virtual void respawnPlayer() = 0;
    virtual void playerKilledEvent(bool isGameOver) = 0;

    virtual std::list<sf::Mouse::Button> getTriggerButtons() const = 0;
    virtual std::list<sf::Keyboard::Key> getTriggerKeys() const = 0;

    virtual void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursor) = 0;
    virtual void trigger(sf::Keyboard::Key key, bool pressed) = 0;

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void drawHUDIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt) = 0;

    int getScore() const;
    void setScore(int p, bool rel = false);

    int getLives() const;
    void setLives(int l, bool rel = false);

    void setRespawnTime(float ticks);
    void updateLivesAndTimer(float dt);
    void setGameOver();


    private :

    Timer m_timeBeforeRespawn;
    int m_lives;
    int m_score;
    bool m_gameOver;
};


#endif // BASIC_ARCADE_LEVEL_HEADER
