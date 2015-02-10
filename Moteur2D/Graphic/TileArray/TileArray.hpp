


#ifndef HEADER_TABLEAU_TILES
#define HEADER_TABLEAU_TILES


#include "Abstractions/AbsTileArray.h"


typedef std::vector< std::shared_ptr<sf::Sprite> > Correspondances;


class TileArrayDrawer : public AbsTileArrayDrawable
{
    public :

    TileArrayDrawer();
    TileArrayDrawer(const TileArray<char>& ntableauTiles, const Correspondances& ncorrespondances, sf::Vector2f dimensionsTiles);

    virtual void setTileArray(const TileArray<char>& ntableauTiles);
    virtual void setTileArray(const TileArray<char>& ntableauTiles, const Correspondances& ncorrespondances, sf::Vector2f dimensionsTiles);
    virtual void setTiles(const Correspondances& ncorrespondances, sf::Vector2f dimensionsTiles);

    protected :
    virtual void drawTileIn(sf::RenderTarget& ncible, unsigned short x, unsigned short y) const;

    private :
    Correspondances t_correspondances;
    sf::Vector2f m_dimensionsTiles;
};


#endif

