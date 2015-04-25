
#ifndef GAME_END_CREDITS_HEADER
#define GAME_END_CREDITS_HEADER

#include "../Moteur2D/Interfaces/Screens/BasicEndCreditsScreen.hpp"


class GameEndCredits : public BasicEndCreditsScreen
{
    public :

    GameEndCredits();
    void setFonts(const sf::Font* f);
    void setAllCredits();

    ScreenPointer loadNextScreen();


    private :

    const sf::Font* m_font;
};


#endif // GAME_END_CREDITS_HEADER
