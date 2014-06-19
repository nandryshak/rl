// make clean && mingw32-g++ -DSFML_STATIC -IC:\SFML-2.1\include -c tile.cpp map.cpp && mingw32-g++ -LC:\SFML-2.1\lib -o game.exe tile.o map.o -lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows
#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
#include "tile.hpp"
#include <vector>

Map::Map(int x, int y) : xSize(x), ySize(y)
{
    Tile emptyTile(sf::Color::Black, sf::Color::Black, ' ');
    std::vector<Tile> row(x, emptyTile);
    std::vector<std::vector<Tile> > mv(y, row);
    map_vec = mv;
}

Map::~Map()
{
    std::cout << "Deleted a map" << std::endl;
}

void Map::FillMap()
{
    std::vector<std::vector<Tile> >::iterator rowIter;
    std::vector<Tile>::iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            // std::cout << "Here's a tile: " << *colIter << endl;
            // Tile tmpTile();
            *colIter = Tile(sf::Color::Black, sf::Color::Black, ' ');
        }
    }
}

void Map::PrintMap()
{
    std::vector<std::vector<Tile> >::const_iterator rowIter;
    std::vector<Tile>::const_iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            std::cout << *colIter << std::endl;
        }
    }
}

void DrawMap(sf::RenderWindow win)
{
    // for each tile in the map, draw it
    // display the window
    win.display();
}

int main()
{
    Map testMap(10, 10);
    testMap.FillMap();
    testMap.PrintMap();

    return 0;
}
