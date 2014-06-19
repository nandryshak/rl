// make clean && mingw32-g++ -DSFML_STATIC -IC:\SFML-2.1\include -c tile.cpp map.cpp && mingw32-g++ -LC:\SFML-2.1\lib -o game.exe tile.o map.o -lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows
#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
#include "tile.hpp"
#include <vector>

Map::Map(int x, int y) : xSize(x), ySize(y)
{
    Tile emptyTile(sf::Color::Black, sf::Color::White, 'X');
    std::vector<Tile> row(x, emptyTile);
    std::vector<std::vector<Tile> > mv(y, row);
    map_vec = mv;
    tileYSize = 24;
    tileXSize = 16;
}

Map::~Map()
{
}

void Map::FillMap(char ch)
{
    std::vector<std::vector<Tile> >::iterator rowIter;
    std::vector<Tile>::iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            Tile tmpTile;
            *colIter = tmpTile;
        }
    }
}

void Map::PrintMap()
{
    std::vector<std::vector<Tile> >::const_iterator rowIter;
    std::vector<Tile>::const_iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {
            std::cout << *colIter;
        }
        std::cout << std::endl;
    }
}

void Map::SetTileSize(int y)
{
    tileYSize = y;
    tileXSize = y / 3 * 2;
}

void Map::DrawMap(sf::RenderWindow &win)
{
    // for each tile in the map, draw it
    sf::Font font;
    font.loadFromFile("DroidSansMono.ttf");

    sf::Text text;
    text.setCharacterSize(this->tileYSize);
    text.setFont(font);

    sf::RectangleShape bg;

    int xpos = 0;
    int ypos = 0;
    std::vector<std::vector<Tile> >::const_iterator rowIter;
    std::vector<Tile>::const_iterator colIter;
    for (rowIter=this->map_vec.begin(); rowIter!=this->map_vec.end(); ++rowIter) {
        for (colIter=(*rowIter).begin(); colIter!=(*rowIter).end(); ++colIter) {

            // draw tile bg
            bg.setSize(sf::Vector2f(this->tileXSize, this->tileYSize));
            bg.setPosition(xpos, ypos);
            bg.setFillColor((*colIter).bgColor);
            win.draw(bg);

            // draw tile text
            text.setString((*colIter).tileChar);
            text.setColor((*colIter).fgColor);
            text.setPosition(xpos + 1, ypos - 4);
            win.draw(text);

            xpos += this->tileXSize;
        }
        xpos = 0;
        ypos += this->tileYSize;
    }
}
