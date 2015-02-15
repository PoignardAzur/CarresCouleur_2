
#ifndef MENU_COUNTER_HEADER
#define MENU_COUNTER_HEADER

#include "Text.hpp"


namespace Menu
{

    // Class representing a Counter displayed on the screen
    class Counter : public ItemAbstraction, public TextObjectAbstraction
    {
        public :

        explicit Counter(FontStyle f = FontStyle(), bool rightAligned = false, int n = 0, int min = 0, int max = 1000, int base = 10);
        explicit Counter(int n, int min = 0, int max = 1000, int base = 10);

        void setValue(int n);
        void setBounds(int min, int max);
//        void setBase(int base);
        void setRightAligned(bool rightAligned);    // sets whether the Counter is drawn at the left or at the right of its box

//      METHODS INHERITED FROM TextObjectAbstraction
//      void setFont(const FontStyle& f);
//      void setFont(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE);
//      void setFont(const sf::Font* f, unsigned int charSize, const sf::Color& c);
//      void setColor(const sf::Color& c);

        sf::Vector2f getSize() const;               // returns the biggest size the Counter can have given its limits


        protected :

        void setFontStyle(const FontStyle& f);
        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void updateOwnSize();                       // is called when m_minimumValue and m_maximumValue are changed
        void updateText();


        private :

        int m_minimumValue;
        int m_maximumValue;

        int m_value;
//        int m_base;

        Text m_drawnText;
        bool m_rightAligned;

        sf::Vector2f m_size;
    };

}


#endif // MENU_COUNTER_HEADER
