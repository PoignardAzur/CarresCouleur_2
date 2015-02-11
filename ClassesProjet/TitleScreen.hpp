

#ifndef TITLE_SCREEN_HEADER
#define TITLE_SCREEN_HEADER

#include "../Moteur2D/Interfaces/PressAnyKeyMenu.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class TitleScreen : public PressAnyKeyMenu
{
    public :

    TitleScreen(AbstractGameInterface* nextInterface, InputsAbstraction* in, const sf::Font* font);
    void drawIn(DrawerAbstraction& window, float dt);


    private :

    Menu::Text m_title;
    Menu::Text m_subtitle;
    const sf::Font* m_font;
};


#endif // TITLE_SCREEN_HEADER
