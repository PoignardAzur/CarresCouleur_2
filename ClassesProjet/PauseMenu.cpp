
#include "PauseMenu.hpp"
#include "Level_HUD.hpp"
#include "Level_1.hpp"
#include "MainMenu.hpp"


uptrt<Menu::AbstractItem> yellowBox(const char* str, Menu::FontStyle& fs);
uptrt<Menu::AbstractItem> redBox(const char* str, Menu::FontStyle& fs);


PauseMenu::PauseMenu() : MenuInterface(false, false)
{
    m_text.setString("Revenir à l'écran titre ?");
}

void PauseMenu::set(const sf::Font* f, InputsAbstraction* in)
{
    setInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);

    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);
    m_yesButton.setSprites(yellowBox("Oui", fs, true), redBox("Oui", fs, true));
    m_noButton.setSprites(yellowBox("Non", fs, true), redBox("Non", fs, true));

    m_yesButton.setFunction
    (
        [f, this]()
        {
            MainMenu* menu = new MainMenu;
            menu->set(getInputs(), f);

            setNextLevel(uptrt<MainMenu>(menu));
            endThisLater();
        }
    );

    m_noButton.setFunction
    (
        [this]()
        {
            endThisLater();
        }
    );

    addButton(&m_yesButton);
    addButton(&m_noButton);
}


bool PauseMenu::isLayered() const
{
    return true;
}

void PauseMenu::escape()
{
    endThisLater();
}


void PauseMenu::drawThisIn(DrawerAbstraction& window, float dt) const
{
    (void) dt;

    sf::RectangleShape rect(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    rect.setFillColor(sf::Color(0, 0, 0, 128));
    window.draw(rect);

    m_text.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2 - 20), Menu::MiddleBottomSide);
    m_yesButton.drawInBox(window, sf::FloatRect(0, WINDOW_HEIGHT / 2 + 10, WINDOW_WIDTH / 2 - 5, 1), Menu::TopRightCorner);
    m_noButton.drawInBox(window, sf::FloatRect(WINDOW_WIDTH / 2 + 5, WINDOW_HEIGHT / 2 + 10, 1, 1), Menu::TopLeftCorner);
}

