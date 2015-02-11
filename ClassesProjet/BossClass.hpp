

#ifndef BOSS_CLASS_HEADER
#define BOSS_CLASS_HEADER

#include "../Moteur2D/GameController.hpp"
#include "../Moteur2D/Interfaces/MetaInterface.hpp"
#include "LevelBase.hpp"


class BossClass : public GameController
{
    public :

    BossClass(up_t<InputsAbstraction> userInputs, sf::RenderWindow* target);

    AbstractGameInterface* interface();
    void update(float dt);
    bool isDone() const;

    private :

    MetaInterface m_interface;
    sf::Font m_font;
};


#endif // BOSS_CLASS_HEADER
