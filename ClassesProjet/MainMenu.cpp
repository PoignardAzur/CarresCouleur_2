
#include "MainMenu.hpp"
#include "../Moteur2D/Interfaces/Menus/TextBox.hpp"

#include "Level_1.hpp"
#include "Level_2.hpp"
#include "Level_3.hpp"
#include "Level_4.hpp"
#include "Level_HUD.hpp"

#include "DefaultMenuButton.hpp"


const int HEIGHT_MENU_TITLE = 60;
const int HEIGHT_FIRST_BUTTON = HEIGHT_MENU_TITLE + 80;
const int GAP_BETWEEN_BUTTONS = 20;


MainMenu::MainMenu() : m_buttons(true, false)
{
    m_text.setString("Sélectionner un niveau");
}

template <typename Level>
std::function<void(void)> MainMenu::getLevelLoadingFunction(const sf::Font* f)
{
    return [this, f]()
    {
        loadNext(uptrt<LevelBase>(new Level), f);
    };
}

void MainMenu::set(InputsAbstraction* in, const sf::Font* f)
{
    setInputs(in);

    m_text.setFont(f, DEFAULT_FONT_SIZE * 2, sf::Color::White);
    Menu::FontStyle fs(f, DEFAULT_FONT_SIZE, sf::Color::White);

    using ButtonPtr = uptrt<Menu::PushButton>;

    ButtonPtr level_1_button = getMenuButton("Niveau 1", fs);
    ButtonPtr level_2_button = getMenuButton("Niveau 2", fs);
    ButtonPtr level_3_button = getMenuButton("Niveau 3", fs);
    ButtonPtr level_4_button = getMenuButton("Niveau 4", fs);
    ButtonPtr quit_button = getMenuButton("Quitter", fs);

    level_1_button->setFunction(getLevelLoadingFunction<Level_1>(f));
    level_2_button->setFunction(getLevelLoadingFunction<Level_2>(f));
    level_3_button->setFunction(getLevelLoadingFunction<Level_3>(f));
    level_4_button->setFunction(getLevelLoadingFunction<Level_4>(f));

    quit_button->setFunction
    (
        [this, f]()
        {
            closeMenu();
        }
    );

    m_buttons.addButton(move(level_1_button));
    m_buttons.addButton(move(level_2_button));
    m_buttons.addButton(move(level_3_button));
    m_buttons.addButton(move(level_4_button));
    m_buttons.addButton(move(quit_button));

    m_buttons.setGapsBetweenButtons(GAP_BETWEEN_BUTTONS);
}


bool MainMenu::isLayered() const
{
    return false;
}


const Menu::ButtonListAbstraction& MainMenu::buttonList() const
{
    return m_buttons;
}

Menu::ButtonListAbstraction& MainMenu::buttonList()
{
    return m_buttons;
}


void MainMenu::drawThisIn(DrawerAbstraction& window, float dt) const
{
    (void) dt;

    m_text.drawInBox(window, sf::FloatRect(0, HEIGHT_MENU_TITLE, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
    m_buttons.drawInBox(window, sf::FloatRect(0, HEIGHT_FIRST_BUTTON, WINDOW_WIDTH, 1), Menu::MiddleTopSide);
}


void MainMenu::loadNext(uptrt<LevelBase> level, const sf::Font* f)
{
    Level_HUD* hud = new Level_HUD;
    hud->setFont(f);

    level->setInputs(getInputs());
    level->setFont(f);
    level->setHUD(uptr(hud));

    endThisLater();
    setNextScreenAndClose(move(level));
}

void MainMenu::escape()
{
    m_buttons.down(true);
}


