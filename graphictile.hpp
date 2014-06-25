#ifndef GRAPHICTILE_H
#define GRAPHICTILE_H

#include <SFML/Graphics.hpp>

int rand256();
sf::Color getRandomColor();
char getRandomChar();

class GraphicTile {
public:
    GraphicTile(sf::Color fg = getRandomColor(), sf::Color bg = getRandomColor(), char ch = getRandomChar());
    GraphicTile(char ch);
    ~GraphicTile();
    sf::Color fgColor;
    sf::Color bgColor;
    char graphicTileChar;
    static const GraphicTile grHallway;
    static const GraphicTile grTopWall;
    static const GraphicTile grSideWall;
    static const GraphicTile grFloor;
    static const GraphicTile grDoor;
    static const GraphicTile grPlayer;
private:
};

std::ostream& operator<<(std::ostream &strm, const GraphicTile &t);
std::ostream& operator<<(std::ostream &strm, const sf::Color &c);

#endif
