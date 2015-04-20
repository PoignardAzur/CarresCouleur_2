
#ifndef MENU_BUTTON_ABSTRACTION_HEADER
#define MENU_BUTTON_ABSTRACTION_HEADER

#include "../../Items/AbstractItem.hpp"


namespace Menu
{

    class ButtonAbstraction : public AbstractItem
    {
        public :

        //virtual bool isGrayed();

        virtual void select() = 0;              // a selected Button has a different appearance, and is the one triggered when
        virtual void deselect() = 0;            // a trigger key (ex: Space) is pressed
        virtual void press() = 0;

        virtual sf::Vector2f getSize() const = 0;

        virtual void left(bool big = false);     // those four commands are useful
        virtual void right(bool big = false);    // for submenus and slides
        virtual void up(bool big = false);       // by default, they do nothing
        virtual void down(bool big = false);

        virtual ~ButtonAbstraction();


        protected :

        virtual void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const = 0;
    };

}


#endif // MENU_BUTTON_ABSTRACTION_HEADER
