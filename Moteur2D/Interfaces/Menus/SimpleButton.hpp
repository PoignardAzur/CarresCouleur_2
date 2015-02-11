

#ifndef SIMPLE_MENU_BUTTON_HEADER
#define SIMPLE_MENU_BUTTON_HEADER

#include "ButtonAbstraction.hpp"
#include "../Items/ItemAbstraction.hpp"
#include <memory>
#include <functional>


namespace Menu
{

    class SimpleButton : public ButtonAbstraction, public ItemAbstraction
    {
        public :

        SimpleButton(ItemAbstraction* unselected = nullptr, ItemAbstraction* selected = nullptr);
        void setSprites(ItemAbstraction* unselected, ItemAbstraction* selected = nullptr);
        void setFunction(std::function<void(void)> triggeredFunction);
        ~SimpleButton() noexcept {};

        void select();
        void deselect();
        void press();

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        const ItemAbstraction* currentSprite() const;
        ItemAbstraction* currentSprite();

        virtual void trigger();


        private :

        bool m_pressed;
        bool m_selected;

        std::unique_ptr<ItemAbstraction> m_unselected_sprite;
        std::unique_ptr<ItemAbstraction> m_selected_sprite;

        std::function<void(void)> m_triggeredFunction;
    };

}


#endif

