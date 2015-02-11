


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "DrawerAbstraction.hpp"



class ObjectDrawer : public DrawerAbstraction
{
    public :

    ObjectDrawer(sf::RenderTarget* t);

    virtual void clear();                               // reset the screen
    virtual void draw(const sf::Drawable& o);
//    void display();


    protected :
    sf::RenderTarget& target(); /// TODO - Change this to getTarget()


    private :
    sf::RenderTarget* m_target;       // use-a
};




#endif

