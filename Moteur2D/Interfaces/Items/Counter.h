

#ifndef MENU_COUNTER_HEADER
#define MENU_COUNTER_HEADER

#include "Text.h"



namespace Menu
{

    class Counter : public AbstractItem, public AbstractTextObject
    {
        public :

        explicit Counter(FontStyle f = FontStyle(), bool rightAligned = false, int n = 0, int min = 0, int max = 1000, int base = 10);
        explicit Counter(int n, int min = 0, int max = 1000, int base = 10);

        void setValue(int n);
        void setBounds(int min, int max);
//        void setBase(int base);

        void setRightAligned(bool rightAligned);

        sf::Vector2f getSize() const;


        protected :

        void setFontStyle(const FontStyle& f);
        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void updateOwnSize();
        void updateText();


        private :

        int m_minimumValue;
        int m_maximumValue;

        int m_value;
//      int m_base;

        Text m_drawnText;
        bool m_rightAligned;

        sf::Vector2f m_size;
    };


}


#endif // MENU_COUNTER_HEADER



