
#ifndef TEXT_OBJECT_ABSTRACTION_HEADER
#define TEXT_OBJECT_ABSTRACTION_HEADER

#include <SFML/Graphics.hpp>

extern const int DEFAULT_FONT_SIZE;


namespace Menu
{

    struct FontStyle
    {
        FontStyle(const sf::Font* n_f = nullptr, unsigned int n_charSize = DEFAULT_FONT_SIZE, const sf::Color& n_c = sf::Color::White);
        FontStyle(const FontStyle& other);

        const sf::Font* f;
        unsigned int charSize;
        sf::Color c;
    };


    class TextObjectAbstraction
    {
        public :

        TextObjectAbstraction();
        virtual ~TextObjectAbstraction();

        void setFont(const FontStyle& f);
        void setFont(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE);
        void setFont(const sf::Font* f, unsigned int charSize, const sf::Color& c);
        void setColor(const sf::Color& c);


        protected :

        virtual void setFontStyle(const FontStyle& f) = 0;
        FontStyle getFontStyle() const;


        private :

        FontStyle m_fontStyle;
    };
}


#endif // TEXT_OBJECT_ABSTRACTION_HEADER
