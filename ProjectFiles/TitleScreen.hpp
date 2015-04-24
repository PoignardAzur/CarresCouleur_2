
#ifndef TITLE_SCREEN_HEADER
#define TITLE_SCREEN_HEADER

#include "Menus/MainMenu.hpp"
#include "../Moteur2D/Interfaces/Screens/PressAnyKeyMenu.hpp"


class TitleScreen : public PressKeyToContinue
{
    public :

    TitleScreen(InputsAbstraction* in, const sf::Font* font);

    void drawIn(DrawerAbstraction& window, float dt) const;
    ScreenPointer getNextScreen();


    protected :

    std::set<sf::Keyboard::Key> getKeysToContinue();


    private :

    Menu::Text m_title;
    Menu::Text m_subtitle;
    Menu::ItemBox m_pressEnter;

    const sf::Font* m_font;
};


#endif // TITLE_SCREEN_HEADER
