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
    private:
        std::string mapName;
        int ySize;
        int xSize;
};

#endif
