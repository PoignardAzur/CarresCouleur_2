

#ifndef MENU_SPRITE_HEADER
#define MENU_SPRITE_HEADER

#include "AbstractItem.h"


namespace Menu
{

    class Sprite : public AbstractItem
    {
        public :

        Sprite();
        Sprite(const sf::Sprite& spr);
        void set(const sf::Sprite& spr);
        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        sf::Sprite m_sprite;
    };

}


#endif // MENU_SPRITE_HEADER
