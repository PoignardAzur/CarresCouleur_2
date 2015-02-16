
#ifndef ABSTRACT_MENU_ITEM_HEADER
#define ABSTRACT_MENU_ITEM_HEADER

#include "../../Graphic/DrawerAbstraction.hpp"


extern bool DRAW_ITEM_HITBOX; // is not const to reduce compile time, should not be modified

namespace Menu
{

    enum Alignement
    {
        TopLeftCorner,
        MiddleTopSide,
        TopRightCorner,

        MiddleLeftSide,
        Center,
        MiddleRightSide,

        BottomLeftCorner,
        MiddleBottomSide,
        BottomRightCorner
    };

    // Represents any item drawn in a menu
    class AbstractItem
    {
        public :

        AbstractItem(AbstractItem* parent = nullptr);
        void setParent(AbstractItem* parent);
        virtual ~AbstractItem() = default;

        virtual void drawIn(DrawerAbstraction& target, sf::Vector2f position, bool drawHitbox = DRAW_ITEM_HITBOX) const;
        // draws the item with 'position' as the top-left corner of its "box"
        virtual void drawInBox(DrawerAbstraction& target, sf::FloatRect box, Alignement a = Center, bool drawHitbox = DRAW_ITEM_HITBOX) const;
        // draws the item with its internal "box" against one of the sides of 'box', or at its center
        virtual sf::Vector2f getSize() const = 0;
        // returns the size of the item's "box"


        protected :

        virtual void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const = 0; // isHitboxDrawn is used for recursion, to draw children's boxes too
        virtual void drawHitboxIn(DrawerAbstraction& target, sf::Vector2f position) const;
        virtual int hashToColor(float x) const;     // used to determine the hitbox's color

        virtual void updateParentSize();    // useful for items that need to change their box's size whenever their children do
        virtual void updateOwnSize();       // this method is called by classes with a m_size attribute when it needs to be modified


        private :

        AbstractItem* m_parent;
    };


    inline bool isLeft(Alignement a)
    {
        return (a == TopLeftCorner) || (a == MiddleLeftSide) || (a == BottomLeftCorner);
    }

    inline bool isRight(Alignement a)
    {
        return (a == TopRightCorner) || (a == MiddleRightSide) || (a == BottomRightCorner);
    }

    inline bool isVerticalMiddle(Alignement a)
    {
        return !(isLeft(a) || isRight(a));
    }

    inline bool isTop(Alignement a)
    {
        return (a == TopLeftCorner) || (a == MiddleTopSide) || (a == TopRightCorner);
    }

    inline bool isBottom(Alignement a)
    {
        return (a == BottomLeftCorner) || (a == MiddleBottomSide) || (a == BottomRightCorner);
    }

    inline bool isHorizontalMiddle(Alignement a)
    {
        return !(isTop(a) || isBottom(a));
    }

    inline bool isSide(Alignement a)
    {
        return (a == MiddleLeftSide) || (a == MiddleTopSide) || (a == MiddleRightSide) || (a == MiddleBottomSide);
    }

    inline bool isCorner(Alignement a)
    {
        return (a == TopLeftCorner) || (a == TopRightCorner) || (a == BottomLeftCorner) || (a == BottomRightCorner);
    }

}


#endif // ABSTRACT_MENU_ITEM_HEADER