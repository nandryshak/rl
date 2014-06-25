#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "window.hpp"
#include "map.hpp"
#include "entity.hpp"

extern std::unique_ptr<sf::RenderWindow> window;

GameWindow::GameWindow(int w, int h, std::string n, Map initMap)
{
    width = w;
    height = h;
    name = n;
    map = initMap;

    // sf::RenderWindow window(sf::VideoMode(w, h), n, sf::Style::Titlebar | sf::Style::Close);
}

GameWindow::~GameWindow()
{
}

// TODO
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
            (*::window).draw(bg);

            // draw tile text
            text.setString((*colIter).grTile.graphicTileChar);
            text.setColor((*colIter).grTile.fgColor);
            text.setPosition(xpos + 1, ypos - 4);
            // this->window.draw(text);
            (*::window).draw(text);

            xpos += map.tileXSize;
        }
        xpos = 0;
        ypos += map.tileYSize;
    }
}

// TODO
void GameWindow::DrawEntity(Entity entity)
{
    
}

// TODO
void GameWindow::DrawPlayer(Entity player)
{
}

// TODO
void GameWindow::DrawEnemyList(std::list<Entity> entList)
{
}

void GameWindow::InitializeWindow()
{
    (*::window).clear();
    this->DrawMap(this->map);
    (*::window).display();
}

void GameWindow::RegenerateRooms()
{
    (*::window).clear(sf::Color::Black);
    this->map.ClearMap();
    this->map.GenerateRooms();
    this->DrawMap(this->map);
    (*::window).display();
}

void GameWindow::Redraw()
{
    (*::window).clear(sf::Color::Black);
    this->DrawMap(this->map);
    (*::window).display();
}

std::ostream& operator << (std::ostream &strm, const GameWindow &gw)
{
    return strm << gw.name;
}
