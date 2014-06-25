#include <string>
#include "graphictile.hpp"
#include "entity.hpp"

Entity::Entity(std::string n, GraphicTile gr, int hp) :
    name(n),
    tile(gr),
    health(hp)
{
}

Entity::~Entity()
{
}

void Entity::Move(int x, int y)
{
}

