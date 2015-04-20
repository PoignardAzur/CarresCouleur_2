
#include "PauseMenu.hpp"
#include "MainMenu.hpp"

#include "Level_HUD.hpp"
#include "Level_1.hpp"

#include "DefaultMenuButton.hpp"


PauseMenu::PauseMenu() : m_buttons(false, false)
{
    m_text.setString("Revenir à l'écran titre ?");
}

void PauseMenu::set(const sf::Font* f, InputsAbstraction* in)
{
    setInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);
    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);

    uptrt<Menu::PushButton> yesButton = getMenuButton("Oui", fs);
    uptrt<Menu::PushButton> noButton = getMenuButton("Non", fs);

    yesButton->setFunction
    (
        [f, this]()
        {
            MainMenu* menu = new MainMenu;
            menu->set(getInputs(), f);

            setNextScreenAndClose(uptr(menu));
        }
    );

    noButton->setFunction
    (
        [this]()
        {
            closeMenu();
        }
    );

    m_buttons.addButton(move(yesButton));
    m_buttons.addButton(move(noButton));

    m_buttons.setGapsBetweenButtons(10);
}


bool PauseMenu::isLayered() const
{
    return true;
}

void PauseMenu::drawThisIn(DrawerAbstraction& window, float dt) const
{
    (void) dt;

    sf::RectangleShape rect(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    rect.setFillColor(sf::Color(0, 0, 0, 128));
    window.draw(rect);

    m_text.drawInBox(window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2 - 20), Menu::MiddleBottomSide);
    m_buttons.drawInBox(window, sf::FloatRect(0, WINDOW_HEIGHT / 2 + 10, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
}


const Menu::ButtonListAbstraction& PauseMenu::buttonList() const
{
    return m_buttons;
}

Menu::ButtonListAbstraction& PauseMenu::buttonList()
{
    return m_buttons;
}

