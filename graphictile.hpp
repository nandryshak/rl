#ifndef GRAPHICTILE_H
#define GRAPHICTILE_H

#include <SFML/Graphics.hpp>

int rand256();
sf::Color getRandomColor();
char getRandomChar();

class GraphicTile {
public:
    GraphicTile(sf::Color fg = getRandomColor(), sf::Color bg = getRandomColor(), char ch = getRandomChar());
    ~GraphicTile();
    void DrawGraphicTile(int x, int y);
    sf::Color fgColor;
    sf::Color bgColor;
    char graphicTileChar;
    static const GraphicTile Hallway;
    static const GraphicTile TopWall;
    static const GraphicTile SideWall;
    static const GraphicTile Floor;
    static const GraphicTile Door;
    static const GraphicTile Player;
private:
};

std::ostream& operator<<(std::ostream &strm, const GraphicTile &t);
std::ostream& operator<<(std::ostream &strm, const sf::Color &c);

#endif
