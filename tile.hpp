#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

int rand256();
sf::Color getRandomColor();
char getRandomChar();

class Tile {
public:
    Tile(sf::Color fg = getRandomColor(), sf::Color bg = getRandomColor(), char ch = getRandomChar());
    ~Tile();
    void DrawTile(int x, int y);
    sf::Color fgColor;
    sf::Color bgColor;
    char tileChar;
private:
};

std::ostream& operator<<(std::ostream &strm, const Tile &t);
std::ostream& operator<<(std::ostream &strm, const sf::Color &c);

#endif
