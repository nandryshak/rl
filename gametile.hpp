#ifndef GAMETILE_H
#define GAMETILE_H

#include <string>
#include "graphictile.hpp"

class GameTile
{
public:
    GameTile(std::string n = "Default String", GraphicTile gt = GraphicTile(), bool passable = true);
    GameTile(const GameTile &gtSource); // copy constructor
    ~GameTile();

    // properties
    std::string name;
    GraphicTile grTile;
    bool isPassable;

    // base tiles
    static const GameTile Hallway;
    static const GameTile TopWall;
    static const GameTile SideWall;
    static const GameTile Floor;
    static const GameTile Door;
    static const GameTile Wall;
    static const GameTile Player;

    // operator overloads
    bool operator == (const GameTile& right);
private:
};

std::ostream& operator << (std::ostream &strm, const GameTile &t);

#endif
