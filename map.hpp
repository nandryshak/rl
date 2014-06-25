#ifndef MAP_H
#define MAP_H

#include <string>
#include <list>
#include "gametile.hpp"
#include "entity.hpp"

class Map {
public:
    Map(int x = 80, int y = 24);                    // 'structors
    // Map(const Map &mSource);                        // copy constructor
    ~Map();

    void FillMap(char ch);                          // fill map with a char. Don't use.
    void ClearMap();                                // Makes all the tiles black and "Empty"
    void PrintMap();                                // print our each tiles char in text
    void SetTileSize(int y);
    void GenerateRooms(int rooms = rand() % 7 + 3); // default of 3-9 rooms

    // properties
    int xSize;
    int ySize;
    int tileXSize;
    int tileYSize;
    std::string mapName;
    std::vector<std::vector<GameTile> > map_vec;

    // MOVED TO window.cpp
    // void DrawMap(sf::RenderWindow &win); // main draw function
private:
    // GENERATION
    void AddRooms(int rooms);
    void AddDoors();
    void ConnectDoors();

    // ADDING MAP SHAPES
    bool PaintRectangle(int width, int height, int x, int y);

};

#endif
