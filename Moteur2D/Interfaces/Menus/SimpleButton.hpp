
#ifndef SIMPLE_MENU_PUSH_BUTTON_HEADER
#define SIMPLE_MENU_PUSH_BUTTON_HEADER

#include "Buttons/PushButton.hpp"


namespace Menu
{

    // POINTER SAFETY : 'triggeredFunction' must be safe when 'press()' is called
    class SimplePushButton : public PushButton
    {
        public :

        explicit SimplePushButton(uptrt<AbstractItem> unselected = nullptr, uptrt<AbstractItem> selected = nullptr, AbstractItem* parent = nullptr);
        void setSprites(uptrt<AbstractItem> unselected, uptrt<AbstractItem> selected = nullptr);

        void setParent(AbstractItem* parent);


        protected :

        const AbstractItem& currentSprite(bool selected) const;   // can be worth nullptr


        private :

        uptrt<AbstractItem> m_unselected_sprite;
        uptrt<AbstractItem> m_selected_sprite;

        AbstractItem* m_parent;
    };

}


#endif // SIMPLE_MENU_PUSH_BUTTON_HEADER
