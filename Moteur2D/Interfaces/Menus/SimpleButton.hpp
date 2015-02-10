

#ifndef SIMPLE_MENU_BUTTON_HEADER
#define SIMPLE_MENU_BUTTON_HEADER

#include "AbstractButton.h"
#include "../Items/AbstractItem.h"
#include <memory>
#include <functional>


namespace Menu
{

    class SimpleButton : public AbstractButton, public AbstractItem
    {
        public :

        SimpleButton(AbstractItem* unselected = nullptr, AbstractItem* selected = nullptr);
        void setSprites(AbstractItem* unselected, AbstractItem* selected = nullptr);
        void setFunction(std::function<void(void)> triggeredFunction);

        void select();
        void deselect();
        void press();

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        const AbstractItem* currentSprite() const;
        AbstractItem* currentSprite();

        virtual void trigger();


        private :

        bool m_pressed;
        bool m_selected;

        std::unique_ptr<AbstractItem> m_unselected_sprite;
        std::unique_ptr<AbstractItem> m_selected_sprite;

        std::function<void(void)> m_triggeredFunction;
    };

}


#endif

