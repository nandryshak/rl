#include <SFML/Graphics.hpp>
#include "map.hpp"

Map::Map(int x, int y) : xSize(x), ySize(y)
{
    Tile mapArray[x];
}

void Map::FillMap()
{
}

void DrawMap(sf::RenderWindow win)
{
    // for each tile in the map, draw it
    // display the window
    win.display();
}
