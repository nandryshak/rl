#ifndef MAP_H
#define MAP_H

#include <string>
#include "tile.hpp"

class Map {
public:
    Map(int, int);
    ~Map();
    void DrawMap(sf::RenderWindow &win);
    void FillMap(char);
    void PrintMap();
    int ySize;
    int xSize;
    void SetTileSize(int);
    std::string mapName;
    std::vector<std::vector<Tile> > map_vec;
private:
    int tileXSize;
    int tileYSize;
};

#endif
