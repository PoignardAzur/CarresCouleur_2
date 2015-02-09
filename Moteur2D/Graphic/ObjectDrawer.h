


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "AbstractDrawer.h"



class ObjectDrawer : public AbstractDrawer
{
    public :

    ObjectDrawer(sf::RenderTarget* cible);
    virtual ~ObjectDrawer() {}

    virtual void clear();                               // reset the screen
    virtual void draw(const sf::Drawable& o);
//    void display();


    protected :
    sf::RenderTarget& target();


    private :
    sf::RenderTarget* m_target;       // use-a
};




#endif

