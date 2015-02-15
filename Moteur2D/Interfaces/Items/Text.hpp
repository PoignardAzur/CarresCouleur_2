
#ifndef MENU_TEXT_HEADER
#define MENU_TEXT_HEADER

#include "ItemAbstraction.hpp"
#include "TextObjectAbstraction.hpp"


namespace Menu
{

    class Text : public ItemAbstraction, public TextObjectAbstraction
    {
        public :

        explicit Text(const std::string& str = "", FontStyle f = FontStyle());
        explicit Text(FontStyle f);
        ~Text() noexcept {};

        void setString(const std::string& str);

//      METHODS INHERITED FROM TextObjectAbstraction
//      void setFont(const FontStyle& f);
//      void setFont(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE);
//      void setFont(const sf::Font* f, unsigned int charSize, const sf::Color& c);
//      void setColor(const sf::Color& c);

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void setFontStyle(const FontStyle& f);


        private :

        sf::Font* m_font;
        sf::Color m_color;
        sf::Text m_text;
    };

}


#endif // MENU_TEXT_HEADER
