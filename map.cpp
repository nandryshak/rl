#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include "map.hpp"
#include "gametile.hpp"
#include "graphictile.hpp"
#include "entity.hpp"

Map::Map(int x, int y) : xSize(x), ySize(y) // useless size vars
{
    GameTile emptyTile("Nothing", GraphicTile::grHallway, true);
    std::vector<GameTile> row(x, emptyTile);
    std::vector<std::vector<GameTile> > mv(y, row);
    map_vec = mv;
    // initialize a default tile size
    tileYSize = 24;
    tileXSize = 16;
}

Map::~Map()
{
}

void Map::FillMap(char ch)      // test member please ignore
{
    std::vector<std::vector<GameTile> >::iterator rowIter;
    std::vector<GameTile>::iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            GameTile tmpTile;
            *colIter = tmpTile;
        }
    }
}

void Map::ClearMap()
{
    std::vector<std::vector<GameTile> >::iterator rowIter;
    std::vector<GameTile>::iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            GameTile tmpTile("Empty", GraphicTile(sf::Color::Black, sf::Color::Black, ' '));
            *colIter = tmpTile;
        }
    }
}

void Map::PrintMap()
{
    std::vector<std::vector<GameTile> >::const_iterator rowIter;
    std::vector<GameTile>::const_iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            std::cout << (*colIter).grTile;
        }
        std::cout << std::endl;
    }
}

void Map::SetTileSize(int y)
{
    tileYSize = y;
    tileXSize = y / 3 * 2;
}

void Map::GenerateRooms(int rooms)
{
    this->AddRooms(rooms);
    // this->AddDoors();
    // this->ConnectDoors();
}

void Map::AddRooms(int rooms)
{
    // get the vars ready to generate rooms
    int width, height, x, y = 0;

    // add `rooms` rooms
    int r = 0;
    while (r < rooms) {
        // roll a random width and height with a maximum size of one third of
        // the map

        width = rand() % (this->xSize / 3) + 1;
        height = rand() % (this->ySize / 3) + 1;

        // don't let the room touch the edge of the map, or painting a wall is
        // impossible
        x = rand() % (this->xSize - 2) + 1;
        y = rand() % (this->ySize - 2) + 1;

        // only paint if the generated room will be in bounds of the map
        if (x + width < this->xSize && y + height < this->ySize) {
            // if PaintRectangle is succesful, we've added a room, so increment
            // `r` by 1.
            if ((*this).PaintRectangle(width, height, x, y)) {
                ++r;
            }
        }
    }
}

void Map::AddDoors()
{
}

void Map::ConnectDoors()
{
}

bool Map::PaintRectangle(int width, int height, int x, int y)
{
    /**
     * A room in a map should look like this:
     *     -----------    Where:
     *     |.........|    - is a TopWall
     *     |.........|    . is a Floor
     *     |.........|    | is a SideWall (pipe character)
     *     -----------
     */

    // check for a pre-existing room. If one exists, return false so `AddRooms`
    // can attempt to generate another.
    for (int ycoord = y - 1; ycoord <= height + y; ++ycoord) {
        for (int xcoord = x - 1; xcoord <= width + x; ++xcoord) {
            // check for floors or walls
            if (this->map_vec[ycoord][xcoord].name == "Floor" ||
                this->map_vec[ycoord][xcoord].name == "Wall") {
                // return false so the caller knows he tried to paint a room on
                // a room.
                return false;
            }
        }
    }

    // we passed the check, so paint a rectangle of Floor tiles surrounded by
    // walls
    for (int ycoord = y - 1; ycoord <= height + y; ++ycoord) {
        for (int xcoord = x - 1; xcoord <= width + x; ++xcoord) {
            if (ycoord == y - 1 || ycoord == height + y) {
                this->map_vec[ycoord][xcoord] = GameTile("Wall", GraphicTile::grTopWall);
            } else if (xcoord == x - 1 || xcoord == width + x) {
                this->map_vec[ycoord][xcoord] = GameTile("Wall", GraphicTile::grSideWall);
            } else {
                this->map_vec[ycoord][xcoord] = GameTile("Floor", GraphicTile::grFloor);
            }
        }
    }

    // and return true
    return true;
}

