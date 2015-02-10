

#ifndef LEVEL_BASE_HEADER
#define LEVEL_BASE_HEADER

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

#define MAX_RESPAWN_DELAY 4.0
#define MIN_CARRES_NUMBER 1
#define MAX_CARRES_NUMBER 6

#include "../Moteur2D/Interfaces/AbstractLevel.hpp"
#include "../Moteur2D/Game/VartList.hpp"
#include "CarreCouleur.hpp"


class Level_HUD;

class LevelBase : public AbstractLevel<float>
{
    public :

    virtual void drawThisIn(AbstractDrawer& window, float dt);
    virtual void updateThis(const float& dt);

    void setFont(const sf::Font* font);
    void setHUD(Level_HUD* hud);

    void setNext();
    virtual LevelBase* getNextLevel() = 0;

    virtual void leftClick(sf::Vector2f pos) = 0;
    virtual void rightClick(sf::Vector2f pos) = 0;

    void generateCarre();
    void generateCarreStream(float dt, float minDelay = MAX_RESPAWN_DELAY / 2, float maxDelay = MAX_RESPAWN_DELAY, int minCarresNumber = MIN_CARRES_NUMBER, int maxCarresNumber = MAX_CARRES_NUMBER);


    protected :

    void increaseScore(int points);
    int score() const;

    const VartList<CarreCouleur>& getCarres() const;
    VartList<CarreCouleur>& getCarres();

    void giveCarres(LevelBase* nextLevel);


    private :

    VartList<CarreCouleur> m_carres;
    float m_timeBeforeRespawn = 0;

    bool m_leftClick = false;
    bool m_rightClick = false;
    bool m_enterPressed = true;

    int m_score = 0;
    Level_HUD* m_hud = nullptr;
    const sf::Font* m_font;
};

#endif // LEVEL_BASE_HEADER
