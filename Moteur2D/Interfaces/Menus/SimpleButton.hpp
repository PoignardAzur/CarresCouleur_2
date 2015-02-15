
#ifndef SIMPLE_MENU_BUTTON_HEADER
#define SIMPLE_MENU_BUTTON_HEADER

#include "ButtonAbstraction.hpp"
#include "../Items/ItemAbstraction.hpp"
#include "up.hpp"
#include <functional>


namespace Menu
{

    class SimpleButton : public ButtonAbstraction, public ItemAbstraction
    {
        public :

        SimpleButton(up_t<ItemAbstraction> unselected = nullptr, up_t<ItemAbstraction> selected = nullptr);
        void setSprites(up_t<ItemAbstraction> unselected, up_t<ItemAbstraction> selected = nullptr);
        void setFunction(std::function<void(void)> triggeredFunction);  // the function called when the method press() is called
        ~SimpleButton() noexcept {};

        void select();
        void deselect();
        void press();

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        const ItemAbstraction* currentSprite() const;   // can be worth nullptr
        ItemAbstraction* currentSprite();

        virtual void trigger();


        private :

        bool m_pressed;
        bool m_selected;

        up_t<ItemAbstraction> m_unselected_sprite;
        up_t<ItemAbstraction> m_selected_sprite;

        std::function<void(void)> m_triggeredFunction;
    };

}


#endif
