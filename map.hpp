#ifndef MAP_H
#define MAP_H

#include <string>
#include "gametile.hpp"

class Map {
public:
    Map(int x, int y);
    ~Map();
    void DrawMap(sf::RenderWindow &win);
    void FillMap(char ch);
    void PrintMap();
    int ySize;
    int xSize;
    void SetTileSize(int y);
    std::string mapName;
    std::vector<std::vector<GameTile> > map_vec;
private:
    int tileXSize;
    int tileYSize;
};

#endif
