#ifndef GAMETILE_H
#define GAMETILE_H

#include <string>
#include "graphictile.hpp"

class GameTile
{
public:
    GameTile(std::string n = "Default String", GraphicTile gt = GraphicTile());
    // Copy contructor
    GameTile(const GameTile &gtSource);
    ~GameTile();
    std::string name;
    GraphicTile grTile;
    
    // base tiles
    static const GameTile Hallway;
    static const GameTile TopWall;
    static const GameTile SideWall;
    static const GameTile Floor;
    static const GameTile Door;
    static const GameTile Wall;

    // operator overloads
    bool operator == (const GameTile& right);
private:
};

#endif
