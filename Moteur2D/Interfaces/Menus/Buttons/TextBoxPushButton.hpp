
#ifndef TEXT_BOX_PUSH_BUTTON_HEADER
#define TEXT_BOX_PUSH_BUTTON_HEADER

#include "../SimpleButton.hpp"
#include "../TextBox.hpp"


namespace Menu
{

    class TextBoxPushButton : public SimplePushButton
    {
        public :

        explicit TextBoxPushButton(const char* str, Menu::FontStyle& fs, sf::Vector2f boxSize, sf::Color unselectedColor, sf::Color selectedColor);
        void setSprites(const char* str, Menu::FontStyle& fs, sf::Vector2f boxSize, sf::Color unselectedColor, sf::Color selectedColor);
    };

}


#endif // TEXT_BOX_PUSH_BUTTON_HEADER
