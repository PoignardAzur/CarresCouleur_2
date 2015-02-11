

#ifndef MENU_LIFE_COUNTER_HEADER
#define MENU_LIFE_COUNTER_HEADER

#include "ItemLine.hpp"
#include "Sprite.hpp"
#include "Counter.hpp"


namespace Menu
{

    class LifeCounter : public ItemAbstraction, public TextObjectAbstraction
    {
        public :

        LifeCounter();

        void setValue(int n);
        void setBounds(int maxDrawable, int max); // Cannot draw more sprites than 'maxDrawable', cannot draw a number higher than 'max'
//        void setBase(int base);

        void setRightAligned(bool rightAligned);
        void setSprite(const sf::Sprite& spr);

        void setGaps(float gap);
        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void setFontStyle(const FontStyle& f);


        private :

        ItemRow m_row;

        int m_count;
        int m_maxDrawable;

        std::shared_ptr<Sprite> m_lifeSprite;
        std::shared_ptr<Text> m_cross;
        std::shared_ptr<Counter> m_counter;

        float m_gap;
        bool m_rightAligned;

        void updateGrid();
    };

}


#endif // MENU_LIFE_COUNTER_HEADER
