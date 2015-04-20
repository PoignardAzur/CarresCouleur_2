
#ifndef MENU_PUSH_BUTTON_HEADER
#define MENU_PUSH_BUTTON_HEADER

#include "ButtonAbstraction.hpp"
#include "up.hpp"
#include <functional>


namespace Menu
{

    // POINTER SAFETY : 'triggeredFunction' must be safe when 'press()' is called
    class PushButton : public ButtonAbstraction
    {
        public :

        // the function called when the method press() is called
        void setFunction(std::function<void(void)> triggeredFunction);

        void select();
        void deselect();
        void press();

        sf::Vector2f getSize() const;
        virtual void setParent(AbstractItem* parent) = 0;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        virtual const AbstractItem& currentSprite(bool selected) const = 0;   // can be worth nullptr

        virtual void trigger();


        private :

        bool m_pressed;
        bool m_selected;

        std::function<void(void)> m_triggeredFunction;
    };

}


#endif // MENU_PUSH_BUTTON_HEADER
