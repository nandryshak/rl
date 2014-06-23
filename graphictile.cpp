#include <iostream>
#include <vector>
#include "graphictile.hpp"
#include <cstdlib>

const sf::Color grey(84, 84, 84);
const sf::Color black(0, 0, 0);
const sf::Color white(255, 255, 255);

const GraphicTile GraphicTile::Hallway(grey, black, ' ');
const GraphicTile GraphicTile::TopWall(grey, black, '-');
const GraphicTile GraphicTile::SideWall(grey, black, '|');
const GraphicTile GraphicTile::Floor(grey, black, '.');
const GraphicTile GraphicTile::Door(white, black, '+');
const GraphicTile GraphicTile::Player(white, black, '@');

GraphicTile::GraphicTile(sf::Color fg,
           sf::Color bg,
           char ch) :
    fgColor(fg),
    bgColor(bg),
    graphicTileChar(ch)
{
}

GraphicTile::~GraphicTile()
{
}

void GraphicTile::DrawGraphicTile(int x, int y)
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
    return ch;
}

std::ostream& operator << (std::ostream &strm, const GraphicTile &t)
{
    return strm << t.graphicTileChar;
}

// for printing out a color. Perhaps move this into a helper class / file..
std::ostream& operator << (std::ostream &strm, const sf::Color &c)
{
    return strm << int(c.r) << "\t"
                << int(c.g) << "\t"
                << int(c.b) << "\t";
}
