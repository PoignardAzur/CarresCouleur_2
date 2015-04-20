
#include "TextBoxPushButton.hpp"


Menu::TextBoxPushButton::TextBoxPushButton(const char* str, Menu::FontStyle& fs, sf::Vector2f boxSize, sf::Color unselectedColor, sf::Color selectedColor)
{
    setSprites(str, fs, boxSize, unselectedColor, selectedColor);
}

void Menu::TextBoxPushButton::setSprites(const char* str, Menu::FontStyle& fs, sf::Vector2f boxSize, sf::Color unselectedColor, sf::Color selectedColor)
{
    SimplePushButton::setSprites(uptr(new Menu::TextBox(boxSize, unselectedColor, str, fs)),
                                 uptr(new Menu::TextBox(boxSize, selectedColor, str, fs)));
}


