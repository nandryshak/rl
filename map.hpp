#ifndef MAP_H
#define MAP_H

#include <string>
#include "gametile.hpp"

class Map {
public:
    Map(int x, int y);                   // 'structors
    ~Map();

    void DrawMap(sf::RenderWindow &win); // main draw function
    void FillMap(char ch);               // fill map with a char. Don't use.
    void ClearMap();                     // Makes all the tiles black and "Empty"
    void PrintMap();                     // print our each tiles char in text

    int xSize;
    int ySize;                           // useless right now

    void SetTileSize(int y);
    std::string mapName;

    void GenerateRooms(int rooms = rand() % 7 + 3); // default of 3-9 rooms
private:
    // GENERATION
    void AddRooms(int rooms); 
    void AddDoors();
    void ConnectDoors();

    // ADDING MAP SHAPES
    bool PaintRectangle(int width, int height, int x, int y);

    std::vector<std::vector<GameTile> > map_vec;
    int tileXSize;
    int tileYSize;
};

#endif
