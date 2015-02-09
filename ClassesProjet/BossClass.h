

#ifndef BOSS_CLASS_HEADER
#define BOSS_CLASS_HEADER

#include "../Moteur2D/GameController.h"
#include "../Moteur2D/Interfaces/MetaInterface.h"
#include "LevelBase.h"


class BossClass : public GameController
{
    public :

    BossClass(AbstractInputs* userInputs, sf::RenderWindow* target);

    AbstractGameInterface<float>* interface();
    void update(float dt);
    bool isDone() const;

    private :

    MetaInterface<float> m_interface;
    sf::Font m_font;
};


#endif // BOSS_CLASS_HEADER
