#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "window.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "global.hpp"

GameWindow::GameWindow(int w, int h, std::string n, Map initMap)
{
    width = w;
    height = h;
    name = n;
    map = initMap;
}

GameWindow::~GameWindow()
{
}

void GameWindow::DrawMap(Map map)
{
    // for each tile in the map, draw it
    sf::Font font;
    font.loadFromFile("DroidSansMono.ttf");

    sf::Text text;
    text.setCharacterSize(map.tileYSize);
    text.setFont(font);

    sf::RectangleShape bg;

    int xpos = 0;
    int ypos = 0;

    std::vector<std::vector<GameTile> >::const_iterator rowIter;
    std::vector<GameTile>::const_iterator colIter;

    for (rowIter=map.map_vec.begin(); rowIter!=map.map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {

            // draw tile bg
            bg.setSize(sf::Vector2f(map.tileXSize, map.tileYSize));
            bg.setPosition(xpos, ypos);
            bg.setFillColor((*colIter).grTile.bgColor);
            // this->window.draw(bg);
            (*::MainGameWindow).draw(bg);

            // draw tile text
            text.setString((*colIter).grTile.graphicTileChar);
            text.setColor((*colIter).grTile.fgColor);
            text.setPosition(xpos + 1, ypos - 4);
            // this->window.draw(text);
            (*::MainGameWindow).draw(text);

            xpos += map.tileXSize;
        }
        xpos = 0;
        ypos += map.tileYSize;
    }
}

void GameWindow::DrawEntity(Entity entity)
{
    
}

void GameWindow::DrawPlayer(Entity player)
{
}

void GameWindow::DrawEnemyList(std::list<Entity> entList)
{
}

void GameWindow::InitializeWindow()
{
    (*::MainGameWindow).clear();
    this->DrawMap(this->map);
    (*::MainGameWindow).display();
}

void GameWindow::RegenerateRooms()
{
    (*::MainGameWindow).clear(sf::Color::Black);
    this->map.ClearMap();
    this->map.GenerateRooms();
    this->DrawMap(this->map);
    (*::MainGameWindow).display();
}

void GameWindow::Redraw()
{
    (*::MainGameWindow).clear(sf::Color::Black);
    this->DrawMap(this->map);
    (*::MainGameWindow).display();
}

std::ostream& operator << (std::ostream &strm, const GameWindow &gw)
{
    return strm << gw.name;
}
