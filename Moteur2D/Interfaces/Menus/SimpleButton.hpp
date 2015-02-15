
#ifndef SIMPLE_MENU_BUTTON_HEADER
#define SIMPLE_MENU_BUTTON_HEADER

#include "ButtonAbstraction.hpp"
#include "../Items/AbstractItem.hpp"
#include "up.hpp"
#include <functional>


namespace Menu
{

    class SimpleButton : public ButtonAbstraction, public AbstractItem
    {
        public :

        explicit SimpleButton(uptrt<AbstractItem> unselected = nullptr, uptrt<AbstractItem> selected = nullptr);
        void setSprites(uptrt<AbstractItem> unselected, uptrt<AbstractItem> selected = nullptr);
        void setFunction(std::function<void(void)> triggeredFunction);  // the function called when the method press() is called
        ~SimpleButton() noexcept {};

        void select();
        void deselect();
        void press();

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        const AbstractItem* currentSprite() const;   // can be worth nullptr
        AbstractItem* currentSprite();

        virtual void trigger();


        private :

        bool m_pressed;
        bool m_selected;

        uptrt<AbstractItem> m_unselected_sprite;
        uptrt<AbstractItem> m_selected_sprite;

        std::function<void(void)> m_triggeredFunction;
    };

}


#endif
