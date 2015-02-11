

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

    add_credit("Game Design", "Olivier FAURE");
    add_credit("Sound Design", "-");
    add_credit("Graphismes", "Olivier FAURE");
    add_credit("Scenario", "-");
    add_credit("Level Design", "-");
    add_credit("Marketing", "-");
    add_credit("Distribution", "-");
}

AbstractGameInterface* GameEndCredits::next()
{
    return nullptr;
}

