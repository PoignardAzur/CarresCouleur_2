

#ifndef TEXT_BOX_HEADER
#define TEXT_BOX_HEADER

#include "../Items/AbstractTextObject.h"
#include "../Items/ItemBox.h"
#include <string>


namespace Menu
{

    class TextBox : public AbstractItem
    {
        public :

        TextBox(sf::Vector2f boxSize = sf::Vector2f(0,0), sf::Color c = sf::Color::White, const std::string& text = "", FontStyle f = FontStyle());
        void set(sf::Vector2f boxSize, sf::Color c, const std::string& text, FontStyle f);

        sf::Vector2f getSize() const;
        // returns the size of the item's "box"


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        // isHitboxDrawn is used for recursion, to draw children's boxes too


        private :

        ItemBox m_box;
    };

}


#endif // TEXT_BOX_HEADER
