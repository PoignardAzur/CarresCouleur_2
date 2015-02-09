



#include "AbsTileArray.h"


void AbsTileArrayDrawable::setArray(const TileArray<char>& ntableauTiles)
{
    t_tiles = ntableauTiles;
}

void AbsTileArrayDrawable::drawIn(sf::RenderTarget& cible, bool checkScreen) const
{
    drawIn(cible, sf::IntRect(0, t_tiles.width(), 0, t_tiles.height()), checkScreen);
}

void AbsTileArrayDrawable::drawIn(sf::RenderTarget& cible, sf::IntRect rect, bool checkScreen) const
{
//    if(checkScreen)
//    checkScreenRectangle(rect);

    for(int i1 = rect.left; i1 < rect.left + rect.width; ++i1)
    {
        for(int i2 = rect.top; i2 < rect.top + rect.height; ++i2)
        {
            drawTileIn(cible, i1, i2);
        }
    }
}


const TileArray<char> AbsTileArrayDrawable::array() const
{
    return t_tiles;
}

TileArray<char> AbsTileArrayDrawable::array()
{
    return t_tiles;
}


