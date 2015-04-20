
#ifndef DEFAULT_MENU_BUTTON_HEADER
#define DEFAULT_MENU_BUTTON_HEADER

#include "../Moteur2D/Interfaces/Menus/Buttons/TextBoxPushButton.hpp"

extern const sf::Vector2f BIG_BUTTON_SIZE;
extern const sf::Vector2f SMALL_BUTTON_SIZE;

uptrt<Menu::PushButton> getMenuButton(const char* str, Menu::FontStyle& fs, bool small = false);


#endif // DEFAULT_MENU_BUTTON_HEADER
