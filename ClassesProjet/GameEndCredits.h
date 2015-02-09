

#ifndef GAME_END_CREDITS_HEADER
#define GAME_END_CREDITS_HEADER

#include "../Moteur2D/Interfaces/SimpleEndCreditsScreen.h"


class GameEndCredits : public SimpleEndCreditsScreen
{
    public :

    GameEndCredits();
    void setFonts(const sf::Font* f);
    void setAllCredits();

    virtual AbstractGameInterface<float>* next();
};


#endif // GAME_END_CREDITS_HEADER
