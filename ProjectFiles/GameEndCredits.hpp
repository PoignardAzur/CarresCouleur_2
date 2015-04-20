
#ifndef GAME_END_CREDITS_HEADER
#define GAME_END_CREDITS_HEADER

#include "../Moteur2D/Interfaces/Screens/BasicEndCreditsScreen.hpp"


class GameEndCredits : public BasicEndCreditsScreen
{
    public :

    GameEndCredits();
    void setInputs(InputsAbstraction* inputs);
    void setFonts(const sf::Font* f);
    void setAllCredits();

    void update(float dt);
    virtual uptrt<GameInterfaceAbstraction> next();


    private :

    const sf::Font* m_font;
    bool m_enterPressed = true;
};


#endif // GAME_END_CREDITS_HEADER
