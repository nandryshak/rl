#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

int rand256();
sf::Color getRandomColor();
char getRandomChar();

class Tile {
public:
    Tile(sf::Color, sf::Color, char ch);
    ~Tile();
    void DrawTile(int, int);
    sf::Color fgColor;
    sf::Color bgColor;
    char tileChar;
private:
};

std::ostream& operator<<(std::ostream &strm, const Tile &t);

#endif
