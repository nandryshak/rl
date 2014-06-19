// -*- compile-command: "make clean && mingw32-g++ -DSFML_STATIC -IC:\\SFML-2.1\\include -c tile.cpp && mingw32-g++ -LC:\\SFML-2.1\\lib -o game.exe tile.o -lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows"; -*-
#include <iostream>
#include <vector>
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
    return ch;
}

std::ostream& operator<<(std::ostream &strm, const Tile &t)
{
    return strm << "Tile(" << t.tileChar << ")";
}

// int main()
// {
//     srand(time(0));
//     std::vector<Tile> tilevector;

//     tilevector.push_back(Tile());
//     tilevector.push_back(Tile());
//     tilevector.push_back(Tile());
//     tilevector.push_back(Tile());
//     tilevector.push_back(Tile());

//     for (std::vector<Tile>::const_iterator iter=tilevector.begin(); iter!=tilevector.end(); ++iter) {
//         std::cout << *iter << std::endl;
//     }

//     return 0;
// }
