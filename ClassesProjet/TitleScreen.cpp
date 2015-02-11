

#include "TitleScreen.hpp"
#include "LevelBase.hpp"

#define TITLE_TEXT "CARRES COULEUR 2"
#define SUBTITLE_TEXT "Le retour de la vengeance"
#define FONT_FILE_NAME "Resources/arial.ttf"


TitleScreen::TitleScreen(AbstractGameInterface* nextInterface, InputsAbstraction* in, const sf::Font* font)
{
    m_font = font;

    setUserInputs(in);
    setNext(up(nextInterface));

    m_title.setString(TITLE_TEXT);
    m_title.setFont(m_font, DEFAULT_FONT_SIZE * 2);
    m_title.setColor(sf::Color::Red);

    m_subtitle.setString(SUBTITLE_TEXT);
    m_subtitle.setFont(m_font, DEFAULT_FONT_SIZE);
    m_subtitle.setColor(sf::Color(200, 200, 0));
}

void TitleScreen::drawIn(DrawerAbstraction& window, float dt)
{
    m_title.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, 2 * WINDOW_HEIGHT / 3));
    m_subtitle.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, 2 * WINDOW_HEIGHT / 3 + 100));
}

