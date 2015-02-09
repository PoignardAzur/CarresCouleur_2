

#ifndef MENU_LABEL_HEADER
#define MENU_LABEL_HEADER

#include "Text.h"
#include <memory>


namespace Menu
{

    // Draws a label next to another item
    class Label : public AbstractItem, public AbstractTextObject
    {
        public :

        explicit Label(AbstractItem* item = nullptr, const std::string& str = "", FontStyle f = FontStyle(), bool horizontalAlignement = true, float gap = 0);

        void setItem(AbstractItem* item);
        void setLabel(const std::string& str);

        void setAlignement(bool horizontal, float gap);
        sf::Vector2f getSize() const;


        protected :

        void setFontStyle(const FontStyle& f);
        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void setOwnSize();


        private :

        std::shared_ptr<AbstractItem> m_item;
        Text m_label;

        float m_gap;
        bool m_horizontalAlignement;

        sf::Vector2f m_size;
    };

}


#endif // MENU_LABEL_HEADER
