#include <iostream>
#include "tile.hpp"
#include <cstdlib>

Tile::Tile(sf::Color fg = getRandomColor(),
           sf::Color bg = getRandomColor(),
           char ch = getRandomChar()) :
           fgColor(fg),
           bgColor(bg),
           tileChar(ch)
{
}

Tile::~Tile()
{
}

void Tile::DrawTile(int x, int y)
{
}

int rand256()
{
    return rand() % 256;
}

sf::Color getRandomColor()
{
    sf::Color randColor(rand256(), rand256(), rand256());
    return randColor;
}

char getRandomChar()
{
    // rand char from ascii
    // from 33 to 126
    // from  ! to   ~
    char ch = rand() % 94 + 33;
}
