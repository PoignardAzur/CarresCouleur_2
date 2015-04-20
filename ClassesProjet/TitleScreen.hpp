
#ifndef TITLE_SCREEN_HEADER
#define TITLE_SCREEN_HEADER

#include "MainMenu.hpp"
#include "../Moteur2D/Interfaces/Screens/PressAnyKeyMenu.hpp"


class TitleScreen : public PressAnyKeyMenu
{
    public :

    TitleScreen(MainMenu* nextInterface, InputsAbstraction* in, const sf::Font* font);
    void drawIn(DrawerAbstraction& window, float dt) const;


    private :

    Menu::Text m_title;
    Menu::Text m_subtitle;
    const sf::Font* m_font;
};


#endif // TITLE_SCREEN_HEADER
