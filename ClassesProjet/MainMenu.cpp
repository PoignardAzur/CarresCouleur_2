
#include "MainMenu.hpp"
#include "../Moteur2D/Interfaces/Menus/TextBox.hpp"

#include "Level_1.hpp"
#include "Level_2.hpp"
#include "Level_3.hpp"
#include "Level_4.hpp"
#include "Level_HUD.hpp"


const sf::Vector2f BIG_BUTTON_SIZE(140, 50);
const sf::Vector2f SMALL_BUTTON_SIZE(100, 50);

const int HEIGHT_MENU_TITLE = 60;
const int HEIGHT_FIRST_BUTTON = HEIGHT_MENU_TITLE + 80;
const int GAP_BETWEEN_BUTTONS = BIG_BUTTON_SIZE.y + 20;


MainMenu::MainMenu() : MenuInterface(true, false)
{
    m_text.setString("Sélectionner un niveau");
}

void MainMenu::set(InputsAbstraction* in, const sf::Font* f)
{
    setInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);
    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);

    m_level_1_button.setSprites(yellowBox("Niveau 1", fs), redBox("Niveau 1", fs));
    m_level_2_button.setSprites(yellowBox("Niveau 2", fs), redBox("Niveau 2", fs));
    m_level_3_button.setSprites(yellowBox("Niveau 3", fs), redBox("Niveau 3", fs));
    m_level_4_button.setSprites(yellowBox("Niveau 4", fs), redBox("Niveau 4", fs));
    m_quit_button.setSprites(yellowBox("Quitter", fs), redBox("Quitter", fs));

    m_level_1_button.setFunction
    (
        [this, f]()
        {
            loadNext(uptrt<LevelBase>(new Level_1), f);
        }
    );

    m_level_2_button.setFunction
    (
        [this, f]()
        {
            loadNext(uptrt<LevelBase>(new Level_2), f);
        }
    );

    m_level_3_button.setFunction
    (
        [this, f]()
        {
            loadNext(uptrt<LevelBase>(new Level_3), f);
        }
    );

    m_level_4_button.setFunction
    (
        [this, f]()
        {
            loadNext(uptrt<LevelBase>(new Level_4), f);
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


void MainMenu::loadNext(uptrt<LevelBase> level, const sf::Font* f)
{
    Level_HUD* hud = new Level_HUD;
    hud->setFont(f);

    level->setInputs(getInputs());
    level->setFont(f);
    level->setHUD(uptr(hud));

    endThisLater();
    setNextLevel(move(level));
}

void MainMenu::escape()
{
    setSelectedButton(4);
}


uptrt<Menu::AbstractItem> yellowBox(const char* str, Menu::FontStyle& fs, bool small)
{
    if (!small)
    return uptr(new Menu::TextBox(BIG_BUTTON_SIZE, sf::Color(120, 120, 0), str, fs));

    else
    return uptr(new Menu::TextBox(SMALL_BUTTON_SIZE, sf::Color(120, 120, 0), str, fs));
}

uptrt<Menu::AbstractItem> redBox(const char* str, Menu::FontStyle& fs, bool small)
{
    if (!small)
    return uptr(new Menu::TextBox(BIG_BUTTON_SIZE, sf::Color::Red, str, fs));

    else
    return uptr(new Menu::TextBox(SMALL_BUTTON_SIZE, sf::Color::Red, str, fs));
}

