#include "gametile.hpp"
#include "graphictile.hpp"
#include <string>
#include <iostream>

const GameTile GameTile::Hallway("Hallway", GraphicTile::Hallway);
const GameTile GameTile::TopWall("Wall", GraphicTile::TopWall);
const GameTile GameTile::SideWall("Wall", GraphicTile::SideWall);
const GameTile GameTile::Floor("Floor", GraphicTile::Floor); 
const GameTile GameTile::Door("Door", GraphicTile::Door);
const GameTile GameTile::Wall("Wall", GraphicTile::SideWall); // Generic wall type
                                                              // only used for
                                                              // comparison

GameTile::GameTile(std::string n, GraphicTile gt) :
    name(n),
    grTile(gt)
{
    
}

GameTile::GameTile(const GameTile &gtSource)
{
    name = gtSource.name;
    grTile = gtSource.grTile;
}

GameTile::~GameTile()
{
}

bool GameTile::operator == (const GameTile& right)
{
    if ((*this).name.compare(right.name) == 0) {
        return true;
    } else {
        return false;
    }
}
