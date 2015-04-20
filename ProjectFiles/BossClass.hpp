
#ifndef BOSS_CLASS_HEADER
#define BOSS_CLASS_HEADER

#include "../Moteur2D/GameController.hpp"
#include "../Moteur2D/Interfaces/Screens/GameInterfaceAbstraction.hpp"
#include "LevelBase.hpp"


class BossClass : public GameController
{
    public :

    BossClass(uptrt<InputsAbstraction> userInputs, sf::RenderWindow* target);

    GameInterfaceAbstraction& interface();
    void update(float dt);
    bool isDone() const;

    private :

    uptrt<GameInterfaceAbstraction> m_interface;
    sf::Font m_font;
    bool m_isDone = false;
};


#endif // BOSS_CLASS_HEADER
