


#ifndef HEADER_TABLEAU_TILES_ABS
#define HEADER_TABLEAU_TILES_ABS


#include <memory>
#include "../Drawable.h"
#include "../../TileArrayFormat.h"



class AbsTileArrayDrawable : public AbstractDrawable
{
    public :

    virtual void setArray(const TileArray<char>& ntableauTiles);
    virtual void drawIn(sf::RenderTarget&, bool checkScreen = false) const;
    virtual void drawIn(sf::RenderTarget&, sf::IntRect rect, bool checkScreen = false) const;

    protected :

//    virtual void checkScreenRectangle(sf::IntRect& rect) const = 0;
    virtual void drawTileIn(sf::RenderTarget& cible, int x, int y) const = 0;

    virtual const TileArray<char> array() const;
    virtual TileArray<char> array();

    private :
    TileArray<char> t_tiles;
};


#endif


