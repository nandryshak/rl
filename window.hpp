#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include "entity.hpp"
#include "map.hpp"

class GameWindow
{
public:
    GameWindow(int w, int h, std::string n, Map initMap);
    ~GameWindow();

    // members
    void DrawEntity(Entity entity, int x, int y);

    // MOVE THESE FROM OTHER FILES
    // map.cpp
    void DrawMap(Map map);
    void DrawPlayer(Entity player);
    void DrawEnemyList(std::list<Entity> entList);
    // main.cpp
    void InitializeWindow();
    void InitializePlayer();
    void RegenerateRooms();
    void Redraw();

    // properties
    std::string name;
    int width;
    int height;
    Map map;

private:
};

std::ostream& operator << (std::ostream &strm, const GameWindow &gw);

#endif
