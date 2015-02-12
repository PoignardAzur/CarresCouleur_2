

#include "GameEndCredits.hpp"


GameEndCredits::GameEndCredits()
{

}

void GameEndCredits::setFonts(const sf::Font* f)
{
    setAllFonts(f, DEFAULT_FONT_SIZE / 2, sf::Color::Red, sf::Color::Yellow, sf::Color(200, 200, 200), sf::Color::White);
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
}

up_t<AbstractGameInterface> GameEndCredits::next()
{
    return up_t<AbstractGameInterface>();
}

