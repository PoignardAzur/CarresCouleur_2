



#include "TileArray.h"




TileArrayDrawer::TileArrayDrawer(const TileArray<char>& ntableauTiles, const Correspondances& ncorrespondances, sf::Vector2f dimensionsTiles)
{
    setTileArray(ntableauTiles, ncorrespondances, dimensionsTiles);
}

void TileArrayDrawer::setTileArray(const TileArray<char>& ntableauTiles)
{
    AbsTileArrayDrawable::setArray(ntableauTiles);
}


void TileArrayDrawer::setTileArray(const TileArray<char>& ntableauTiles, const Correspondances& ncorrespondances, sf::Vector2f dimensionsTiles)
{
    setTileArray(ntableauTiles);
    setTiles(ncorrespondances, dimensionsTiles);
}

void TileArrayDrawer::setTiles(const Correspondances& ncorrespondances, sf::Vector2f dimensionsTiles)
{
    t_correspondances = ncorrespondances;
    m_dimensionsTiles = dimensionsTiles;
}



void TileArrayDrawer::drawTileIn(sf::RenderTarget& ncible, unsigned short x, unsigned short y) const
{
    t_correspondances[ array().element(x,y) ]->setPosition(x * m_dimensionsTiles.x, y * m_dimensionsTiles.y);
    ncible.draw(*(t_correspondances[ array().element(x,y) ]));
}






