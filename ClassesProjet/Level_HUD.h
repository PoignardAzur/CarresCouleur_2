

#ifndef LEVEL_HUD_HEADER
#define LEVEL_HUD_HEADER

#include "LevelBase.h"
#include "../Moteur2D/Interfaces/AbstractHUD.h"
#include "../Moteur2D/Interfaces/Items/Counter.h"
#include "../Moteur2D/Interfaces/Items/ItemBox.h"
#include <list>


class Level_HUD : public AbstractHUD<float, LevelBase>
{
    public :

    Level_HUD();

    void setFont(const sf::Font* font);
    void setLevel(LevelBase* level);
    void update(const float& dt);

    void drawIn(AbstractDrawer& window, LevelBase* level, float dt);
    void increaseScore(int points, bool draw = true);


    private :

    Menu::Counter* m_score_ptr;
    Menu::ItemBox m_box;
    int m_scoreValue = 0;
    const sf::Font* m_font;

    std::list<std::pair<float, int>> m_plussesList;
};


#endif // LEVEL_HUD_HEADER
