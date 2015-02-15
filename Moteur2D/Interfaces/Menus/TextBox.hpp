
#ifndef TEXT_BOX_HEADER
#define TEXT_BOX_HEADER

#include "../Items/TextObjectAbstraction.hpp"
#include "../Items/ItemBox.hpp"
#include <string>


namespace Menu
{

    // Basic way to draw a button : a text in a colored box
    class TextBox : public ItemAbstraction
    {
        public :

        explicit TextBox(sf::Vector2f boxSize = sf::Vector2f(0,0), sf::Color c = sf::Color::White, const std::string& text = "", FontStyle f = FontStyle());
        void set(sf::Vector2f boxSize, sf::Color c, const std::string& text, FontStyle f);

        sf::Vector2f getSize() const;

        protected :
        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;

        private :
        ItemBox m_box;
    };

}


#endif // TEXT_BOX_HEADER
