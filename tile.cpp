#include <iostream>
#include <vector>
#include "tile.hpp"
#include <cstdlib>

const sf::Color grey(84, 84, 84);
const sf::Color black(0, 0, 0);
const sf::Color white(255, 255, 255);

const Tile Tile::Wall(grey, black, '#');
const Tile Tile::Floor(grey, black, '.');
const Tile Tile::Door(white, black, 'D');
const Tile Tile::Player(white, black, '@');

Tile::Tile(sf::Color fg,
           sf::Color bg,
           char ch) :
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
    return ch;
}

std::ostream& operator << (std::ostream &strm, const Tile &t)
{
    return strm << t.tileChar;
}

std::ostream& operator << (std::ostream &strm, const sf::Color &c)
{
    return strm << int(c.r) << "\t"
                << int(c.g) << "\t"
                << int(c.b) << "\t";
}
