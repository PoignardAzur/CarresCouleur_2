
#ifndef LEVEL_BASE_HEADER
#define LEVEL_BASE_HEADER

#include "Level_HUD.hpp"
#include "../Moteur2D/Interfaces/AbstractLevel.hpp"
#include "../Moteur2D/Game/VartList.hpp"
#include "CarreCouleur.hpp"
#include "PauseMenu.hpp"


extern const int WINDOW_HEIGHT;
extern const int WINDOW_WIDTH;

extern const float MAX_RESPAWN_DELAY;
extern const int MIN_CARRES_NUMBER;
extern const int MAX_CARRES_NUMBER;


class Level_HUD;

class LevelBase : public AbstractLevel
{
    public :

    void setFont(const sf::Font* font);
    void setHUD(uptrt<Level_HUD> hud);

    void setNext();
    virtual uptrt<LevelBase> getNextLevel() = 0;

    virtual void leftClick(sf::Vector2f pos) = 0;
    virtual void rightClick(sf::Vector2f pos) = 0;

    void generateCarre();
    void generateCarreStream(float dt, float minDelay = MAX_RESPAWN_DELAY / 2, float maxDelay = MAX_RESPAWN_DELAY, int minCarresNumber = MIN_CARRES_NUMBER, int maxCarresNumber = MAX_CARRES_NUMBER);


    protected :

    std::list<sf::Mouse::Button> getTriggerButtons() const;
    std::list<sf::Keyboard::Key> getTriggerKeys() const;

    void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursor);
    void trigger(sf::Keyboard::Key key, bool pressed);

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const;
    virtual void drawHUDIn(DrawerAbstraction& window, float dt) const;
    virtual void updateThis(float dt);

    void increaseScore(int points, bool draw = true);
    int score() const;

    const VartList<CarreCouleur>& getCarres() const;
    VartList<CarreCouleur>& getCarres();
    void addCarre(uptrt<CarreCouleur> vart, sf::Vector2f pos);

    void giveCarres(LevelBase* nextLevel);


    private :

    uptrt<Level_HUD> m_hud;
    VartList<CarreCouleur> m_carres;
    float m_timeBeforeRespawn = 0;

    PauseMenu* m_pauseMenu;

    int m_score = 0;
    const sf::Font* m_font = nullptr;
};


#endif // LEVEL_BASE_HEADER
