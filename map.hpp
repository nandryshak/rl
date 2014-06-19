#ifndef MAP_H
#define MAP_H

#include <string>
#include "tile.hpp"

class Map {
public:
    Map(int, int);
    ~Map();
    void DrawMap();
    void FillMap();
    void PrintMap();
    std::string mapName;
    int ySize;
    int xSize;
    std::vector<std::vector<Tile> > map_vec;
private:
};

#endif
