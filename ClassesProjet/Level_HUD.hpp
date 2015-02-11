

#ifndef LEVEL_HUD_HEADER
#define LEVEL_HUD_HEADER

#include "../Moteur2D/Interfaces/AbstractHUD.hpp"
#include "../Moteur2D/Interfaces/Items/Counter.hpp"
#include "../Moteur2D/Interfaces/Items/ItemBox.hpp"
#include <list>


class LevelBase;

class Level_HUD : public AbstractHUD<LevelBase>
{
    public :

    Level_HUD();
    void setFont(const sf::Font* font);
    void update(float dt);

    void drawIn(DrawerAbstraction& window, const LevelBase& level, float dt);
    void increaseScore(int points, bool draw = true);


    private :

    const sf::Font* m_font;     // use-a
    Menu::Counter* m_score_ptr; // use-a
    int m_scoreValue = 0;

    Menu::ItemBox m_box;
    std::list<std::pair<float, int>> m_plussesList;
};


#endif // LEVEL_HUD_HEADER
