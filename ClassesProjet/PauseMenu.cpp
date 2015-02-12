

#include "PauseMenu.hpp"
#include "Level_HUD.hpp"
#include "Level_1.hpp"
#include "MainMenu.hpp"

#define BUTTON_SIZE sf::Vector2f(100, 50)


PauseMenu::PauseMenu() : Menu::MenuAbstraction(false, false)
{
    m_text.setString("Revenir à l'écran titre ?");
}

void PauseMenu::set(const sf::Font* f, InputsAbstraction* in)
{
    setInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);

    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);
    m_yesButton.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Oui", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Oui", fs));
    m_noButton.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Non", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Non", fs));

    m_yesButton.setFunction
    (
        [f, this]()
        {
            MainMenu* menu = new MainMenu;
            menu->set(f, getInputs());

            setNextLevel(up_t<MainMenu>(menu));
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

void PauseMenu::setInputs(InputsAbstraction* in)
{
    AbstractGameInterface::setInputs(in);
}


bool PauseMenu::isLayered() const
{
    return true;
}

void PauseMenu::close()
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

void PauseMenu::updateThis(float dt)
{
    (void) dt;

    bool leftPressed = getInputs()->getKeyboardButtons()[sf::Keyboard::Left];
    bool rightPressed = getInputs()->getKeyboardButtons()[sf::Keyboard::Right];

    if (leftPressed && !rightPressed)
    left();

    if (rightPressed && !leftPressed)
    right();

    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Space] || getInputs()->getKeyboardButtons()[sf::Keyboard::Return])
    press();
}

