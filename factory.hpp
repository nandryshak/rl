#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include <memory>
#include <list>
#include "entity.hpp"

class EntityFactory
{
public:
    EntityFactory();
    ~EntityFactory();
    
    // member functions
    Entity makePlayer();
    Entity makeEnemy();

    // properties
    std::list<Entity> enemyList;
private:
};

#endif
