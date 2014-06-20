// -*- compile-command: "make -k"; -*-
#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
#include "graphictile.hpp"

int main()
{
    // seed random number gen
    srand(time(0));

    // window size (in tiles)
    int charsWide = 80;
    int charsTall = 24;

    Map testMap(charsWide, charsTall);
    testMap.FillMap('X');

    int tileHeight = 15;
    int tileWidth = tileHeight / 3 * 2;
    testMap.SetTileSize(tileHeight);

    int screenWidth = tileWidth * charsWide;
    int screenHeight = tileHeight * charsTall;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "nannyRL",
                            sf::Style::Titlebar | sf::Style::Close);
    window.clear();

    testMap.DrawMap(window);

    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

    }

    return 0;
}
