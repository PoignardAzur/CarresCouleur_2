

#ifndef MENU_TEXT_HEADER
#define MENU_TEXT_HEADER

#include "AbstractItem.h"
#include "AbstractTextObject.h"


namespace Menu
{

    class Text : public AbstractItem, public AbstractTextObject
    {
        public :

        explicit Text(const std::string& str = "", FontStyle f = FontStyle());
        explicit Text(FontStyle f);

        void setString(const std::string& str);

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void setFontStyle(const FontStyle& f);


        private :

        sf::Font* m_font;
        sf::Color m_color;
        sf::Text m_text;
    };

}


#endif // MENU_TEXT_HEADER
