#ifndef ENTITY_H
#define ENTITY_H

#include "graphictile.hpp"

class Entity
{
public:
    Entity(std::string n, GraphicTile gr, int hp);
    ~Entity();
    
    // member functions
    void Move(int x, int y);

    // properties
    std::string name;
    GraphicTile tile;
    int health;
private:
};

#endif
