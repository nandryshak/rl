#include <list>
#include "factory.hpp"
#include "entity.hpp"
#include "gametile.hpp"

EntityFactory::EntityFactory()
{
}

EntityFactory::~EntityFactory()
{
}

Entity makePlayer()
{
    std::string name = "You";
    int health = 10;

    Entity p(name, GraphicTile::grPlayer, health);

    return p;
}

Entity makeEnemy()
{
    std::string name = "Enemy";
    GraphicTile tile('e');
    int health = 5;

    Entity enemy(name, tile, health);

    return enemy;
}
