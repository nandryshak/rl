#include "gametile.hpp"
#include "graphictile.hpp"
#include <string>
#include <iostream>

const GameTile GameTile::Player("Player", GraphicTile::grPlayer, false);
const GameTile GameTile::Hallway("Hallway", GraphicTile::grHallway, true);
const GameTile GameTile::TopWall("Wall", GraphicTile::grTopWall, false);
const GameTile GameTile::SideWall("Wall", GraphicTile::grSideWall, false);
const GameTile GameTile::Floor("Floor", GraphicTile::grFloor, true);
const GameTile GameTile::Door("Door", GraphicTile::grDoor, false);
const GameTile GameTile::Wall("Wall", GraphicTile::grSideWall, false);

GameTile::GameTile(std::string n, GraphicTile gt, bool passable) :
    name(n),
    grTile(gt),
    isPassable(passable)
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

std::ostream& operator << (std::ostream &strm, const GameTile &t)
{
    return strm << t.name;
}
