
#ifndef ITEM_LINE_HEADER
#define ITEM_LINE_HEADER

#include "AbstractItemLine.hpp"


namespace Menu
{

    class ItemLine : public AbstractItemLine
    {
        public :

        ItemLine();
        explicit ItemLine(std::vector<SharedItem> items, float gaps = 0, bool vertical = true);

        void setVertical(bool vertical);
        bool isVertical() const;


        private :

        bool m_vertical = true;
    };


    class VerticalItemLine : public AbstractItemLine
    {
        public :

        VerticalItemLine();
        explicit VerticalItemLine(std::vector<SharedItem> items, float gaps = 0);


        protected :

        bool isVertical() const;
    };


    class HorizontalItemLine : public AbstractItemLine
    {
        public :

        HorizontalItemLine();
        explicit HorizontalItemLine(std::vector<SharedItem> items, float gaps = 0);


        protected :

        bool isVertical() const;
    };

}


#endif // ITEM_LINE_HEADER
