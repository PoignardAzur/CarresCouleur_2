
#include "DefaultMenuButton.hpp"


const sf::Vector2f BIG_BUTTON_SIZE(140, 50);
const sf::Vector2f SMALL_BUTTON_SIZE(100, 50);

const sf::Color UNSELECTED_BUTTON_COLOR = sf::Color(120, 120, 0);
const sf::Color SELECTED_BUTTON_COLOR = sf::Color::Red;


uptrt<Menu::PushButton> getMenuButton(const char* str, Menu::FontStyle& fs, bool small)
{
    return uptr(new Menu::TextBoxPushButton(str, fs, small ? SMALL_BUTTON_SIZE : BIG_BUTTON_SIZE, UNSELECTED_BUTTON_COLOR, SELECTED_BUTTON_COLOR));
}

