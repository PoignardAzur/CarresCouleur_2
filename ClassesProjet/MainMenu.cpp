

#include "MainMenu.hpp"
#include "../Moteur2D/Interfaces/Menus/TextBox.hpp"

#include "Level_1.hpp"
#include "Level_2.hpp"
#include "Level_3.hpp"
#include "Level_4.hpp"
#include "Level_HUD.hpp"

#define BUTTON_SIZE sf::Vector2f(140, 50)

#define HEIGHT_MENU_TITLE 60
#define HEIGHT_FIRST_BUTTON HEIGHT_MENU_TITLE + 80
#define GAP_BETWEEN_BUTTONS (BUTTON_SIZE.y + 20)


MainMenu::MainMenu() : Menu::MenuAbstraction(true, false)
{
    m_text.setString("Sélectionner un niveau");
}

void MainMenu::set(const sf::Font* f, InputsAbstraction* in)
{
    setUserInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);

    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);

    m_level_1_button.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Niveau 1", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Niveau 1", fs));
    m_level_2_button.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Niveau 2", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Niveau 2", fs));
    m_level_3_button.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Niveau 3", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Niveau 3", fs));
    m_level_4_button.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Niveau 4", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Niveau 4", fs));
    m_quit_button.setSprites(new Menu::TextBox(BUTTON_SIZE, sf::Color(120, 120, 0), "Quitter", fs), new Menu::TextBox(BUTTON_SIZE, sf::Color::Red, "Quitter", fs));

    m_level_1_button.setFunction
    (
        [this, f]()
        {
            load(new Level_1, f);
        }
    );

    m_level_2_button.setFunction
    (
        [this, f]()
        {
            load(new Level_2, f);
        }
    );

    m_level_3_button.setFunction
    (
        [this, f]()
        {
            load(new Level_3, f);
        }
    );

    m_level_4_button.setFunction
    (
        [this, f]()
        {
            load(new Level_4, f);
        }
    );

    m_quit_button.setFunction
    (
        [this, f]()
        {
            endThisLater();
        }
    );

    addButton(&m_level_1_button);
    addButton(&m_level_2_button);
    addButton(&m_level_3_button);
    addButton(&m_level_4_button);
    addButton(&m_quit_button);
}

bool MainMenu::isLayered() const
{
    return false;
}


void MainMenu::drawThisIn(DrawerAbstraction& window, float dt)
{
    m_text.drawInBox(window, sf::FloatRect(0, HEIGHT_MENU_TITLE, WINDOW_WIDTH, 1), Menu::MiddleTopSide);

    m_level_1_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_level_2_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_level_3_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + 2*GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_level_4_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + 3*GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);

    m_quit_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + 4*GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
}


void MainMenu::updateThis(const float& dt)
{
    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Up])
    {
        if (!m_upPressed)
        up();

        m_upPressed = true;
    }

    else
    m_upPressed = false;


    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Down])
    {
        if (!m_downPressed)
        down();

        m_downPressed = true;
    }

    else
    m_downPressed = false;

    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Space])
    {
        if (!m_spacePressed)
        press();

        m_spacePressed = true;
    }

    else
    m_spacePressed = false;

    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Return])
    {
        if (!m_enterPressed)
        press();

        m_enterPressed = true;
    }

    else
    m_enterPressed = false;
}


void MainMenu::load(LevelBase* level, const sf::Font* f)
{
    level->setUserInputs(getInputs());

    Level_HUD* hud = new Level_HUD;

    hud->setFont(f);
    hud->setLevel(level);

    endThisLater();
    setNextLevel(hud);
}

