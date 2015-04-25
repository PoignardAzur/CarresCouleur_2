
#include "GameEndCredits.hpp"
#include "Menus/MainMenu.hpp"


GameEndCredits::GameEndCredits()
{

}

void GameEndCredits::setFonts(const sf::Font* f)
{
    setAllFonts(f, DEFAULT_FONT_SIZE / 2, sf::Color::Red, sf::Color::Yellow, sf::Color(200, 200, 200), sf::Color::White);
    m_font = f;
}

void GameEndCredits::setAllCredits()
{
    setGap(30);

    add_title("CARRES COULEUR 2");
    add_subtitle("Le retour de la vengeance");

    add_credit("Game Design", "Olivier FAURE", 10);
    add_credit("Sound Design", "-", 10);
    add_credit("Graphismes", "Olivier FAURE", 10);
    add_credit("Scenario", "-", 10);
    add_credit("Level Design", "-", 10);
    add_credit("Marketing", "-", 10);
    add_credit("Distribution", "-", 10);
    add_credit("Testeur principal", "Marc FAURE", 10);
}

uptrt<ScreenAbstraction> GameEndCredits::loadNextScreen()
{
    MainMenu* menu = new MainMenu;
    menu->set(getInputs(), m_font);
    return uptr(menu);
}

