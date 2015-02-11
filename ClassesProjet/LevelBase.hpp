

#ifndef LEVEL_BASE_HEADER
#define LEVEL_BASE_HEADER

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

#define MAX_RESPAWN_DELAY 4.0
#define MIN_CARRES_NUMBER 1
#define MAX_CARRES_NUMBER 6

#include "Level_HUD.hpp"
#include "../Moteur2D/Interfaces/AbstractLevel.hpp"
#include "../Moteur2D/Game/VartList.hpp"
#include "CarreCouleur.hpp"


class Level_HUD;

class LevelBase : public AbstractLevel
{
    public :

    void setFont(const sf::Font* font);
    void setHUD(up_t<Level_HUD> hud);

    void setNext();
    virtual up_t<LevelBase> getNextLevel() = 0;

    virtual void leftClick(sf::Vector2f pos) = 0;
    virtual void rightClick(sf::Vector2f pos) = 0;

    void generateCarre();
    void generateCarreStream(float dt, float minDelay = MAX_RESPAWN_DELAY / 2, float maxDelay = MAX_RESPAWN_DELAY, int minCarresNumber = MIN_CARRES_NUMBER, int maxCarresNumber = MAX_CARRES_NUMBER);


    protected :

    virtual void drawThisIn(DrawerAbstraction& window, float dt);
    virtual void drawHUDIn(DrawerAbstraction& window, float dt);
    virtual void updateThis(float dt);

    void increaseScore(int points);
    int score() const;

    const VartList<CarreCouleur>& getCarres() const;
    VartList<CarreCouleur>& getCarres();
    void addCarre(up_t<CarreCouleur> vart, sf::Vector2f pos);

    void giveCarres(LevelBase* nextLevel);


    private :

    up_t<Level_HUD> m_hud;
    VartList<CarreCouleur> m_carres;
    float m_timeBeforeRespawn = 0;

    bool m_leftClick = false;
    bool m_rightClick = false;
    bool m_enterPressed = true;

    int m_score = 0;
    const sf::Font* m_font;
};

#endif // LEVEL_BASE_HEADER
