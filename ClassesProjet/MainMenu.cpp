

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
    setInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);

    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);
    sf::Color yellow(120, 120, 0);
    sf::Color red = sf::Color::Red;

    m_level_1_button.setSprites(new Menu::TextBox(BUTTON_SIZE, yellow, "Niveau 1", fs), new Menu::TextBox(BUTTON_SIZE, red, "Niveau 1", fs));
    m_level_2_button.setSprites(new Menu::TextBox(BUTTON_SIZE, yellow, "Niveau 2", fs), new Menu::TextBox(BUTTON_SIZE, red, "Niveau 2", fs));
    m_level_3_button.setSprites(new Menu::TextBox(BUTTON_SIZE, yellow, "Niveau 3", fs), new Menu::TextBox(BUTTON_SIZE, red, "Niveau 3", fs));
    m_level_4_button.setSprites(new Menu::TextBox(BUTTON_SIZE, yellow, "Niveau 4", fs), new Menu::TextBox(BUTTON_SIZE, red, "Niveau 4", fs));
    m_quit_button.setSprites(new Menu::TextBox(BUTTON_SIZE, yellow, "Quitter", fs), new Menu::TextBox(BUTTON_SIZE, red, "Quitter", fs));

    m_level_1_button.setFunction
    (
        [this, f]()
        {
            load(up_t<LevelBase>(new Level_1), f);
        }
    );

    m_level_2_button.setFunction
    (
        [this, f]()
        {
            load(up_t<LevelBase>(new Level_2), f);
        }
    );

    m_level_3_button.setFunction
    (
        [this, f]()
        {
            load(up_t<LevelBase>(new Level_3), f);
        }
    );

    m_level_4_button.setFunction
    (
        [this, f]()
        {
            load(up_t<LevelBase>(new Level_4), f);
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

void MainMenu::setInputs(InputsAbstraction* inputs)
{
    AbstractGameInterface::setInputs(inputs);

    std::map<sf::Mouse::Button, InputsAbstraction::mouseEvent> mouseEvents;
    std::map<sf::Keyboard::Key, InputsAbstraction::keyboardEvent> keyboardEvents;

    keyboardEvents[sf::Keyboard::Up] = [this](bool pressed)
    {
        if (pressed)
        {
            up(false);
        }
    };

    keyboardEvents[sf::Keyboard::Down] = [this](bool pressed)
    {
        if (pressed)
        {
            down(false);
        }
    };

    keyboardEvents[sf::Keyboard::Space] = [this](bool pressed)
    {
        if (pressed)
        {
            press();
        }
    };

    keyboardEvents[sf::Keyboard::Return] = [this](bool pressed)
    {
        if (pressed)
        {
            press();
        }
    };

    keyboardEvents[sf::Keyboard::Escape] = [this](bool pressed)
    {
        if (pressed)
        {
            setSelectedButton(4);
        }
    };

    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
}


bool MainMenu::isLayered() const
{
    return false;
}


void MainMenu::drawThisIn(DrawerAbstraction& window, float dt) const
{
    (void) dt;

    m_text.drawInBox(window, sf::FloatRect(0, HEIGHT_MENU_TITLE, WINDOW_WIDTH, 1), Menu::MiddleTopSide);

    m_level_1_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_level_2_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_level_3_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + 2*GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_level_4_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + 3*GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);

    m_quit_button.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON + 4*GAP_BETWEEN_BUTTONS, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
}


void MainMenu::updateThis(float dt)
{
    (void) dt;
}


void MainMenu::load(up_t<LevelBase> level, const sf::Font* f)
{
    Level_HUD* hud = new Level_HUD;
    hud->setFont(f);

    level->setInputs(getInputs());
    level->setFont(f);
    level->setHUD(up_t<Level_HUD>(hud));

    endThisLater();
    setNextLevel(mv(level));
}

