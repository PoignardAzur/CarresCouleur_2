
#include "TitleScreen.hpp"
#include "LevelBase.hpp"
#include "Menus/MainMenu.hpp"

const char* const TITLE_TEXT = "CARRES COULEUR 2";
const char* const SUBTITLE_TEXT = "Le retour de la vengeance";
const char* const PRESS_ENTER_TEXT = "Appuyez sur Entrée pour continuer";


TitleScreen::TitleScreen(InputsAbstraction* in, const sf::Font* font)
{
    m_font = font;

    setInputs(in);

    m_title.setString(TITLE_TEXT);
    m_title.setFont(m_font, DEFAULT_FONT_SIZE * 2);
    m_title.setColor(sf::Color::Red);

    m_subtitle.setString(SUBTITLE_TEXT);
    m_subtitle.setFont(m_font, DEFAULT_FONT_SIZE);
    m_subtitle.setColor(sf::Color(200, 200, 0));

    uptrt<Menu::Text> pressEnterText(new Menu::Text);
    pressEnterText->setString(PRESS_ENTER_TEXT);
    pressEnterText->setFont(m_font, DEFAULT_FONT_SIZE / 2);
    pressEnterText->setColor(sf::Color::White);

    m_pressEnter.setItem(move(pressEnterText));
    m_pressEnter.setSize(sf::Vector2f(10, 10), true);
    m_pressEnter.setColor(sf::Color(128, 128, 128));
}


void TitleScreen::drawIn(DrawerAbstraction& window, float dt) const
{
    (void) dt;

    m_title.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, 2 * WINDOW_HEIGHT / 3));
    m_subtitle.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, 2 * WINDOW_HEIGHT / 3 + 100));
    m_pressEnter.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), Menu::BottomRightCorner);
}

uptrt<ScreenAbstraction> TitleScreen::loadNextScreen()
{
    uptrt<MainMenu> menu(new MainMenu);
    menu->set(getInputs(), m_font);
    return move(menu);
}

std::set<sf::Keyboard::Key> TitleScreen::getKeysToContinue()
{
    return {sf::Keyboard::Space, sf::Keyboard::Return};
}

