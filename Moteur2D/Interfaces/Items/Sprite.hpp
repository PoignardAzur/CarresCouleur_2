

#ifndef MENU_SPRITE_HEADER
#define MENU_SPRITE_HEADER

#include "ItemAbstraction.hpp"


namespace Menu
{

    class Sprite : public ItemAbstraction
    {
        public :

        Sprite();
        Sprite(const sf::Sprite& spr);
        void set(const sf::Sprite& spr);
        ~Sprite() noexcept {}

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        sf::Sprite m_sprite;
    };

}


#endif // MENU_SPRITE_HEADER
