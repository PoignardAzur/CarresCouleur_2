
#ifndef BOSS_CLASS_HEADER
#define BOSS_CLASS_HEADER

#include "../Moteur2D/GameController.hpp"
#include "../Moteur2D/Interfaces/Screens/ScreenAbstraction.hpp"
#include "LevelBase.hpp"


class BossClass : public GameController
{
    public :

    BossClass(uptrt<InputsAbstraction> userInputs, sf::RenderWindow* target);

    ScreenAbstraction& interface();
    void update(float dt);
    bool isDone() const;

    private :

    uptrt<ScreenAbstraction> m_screen;
    sf::Font m_font;
    bool m_isDone = false;
};


#endif // BOSS_CLASS_HEADER
