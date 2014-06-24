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
    testMap.GenerateRooms();

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
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::Q:
                            window.close();
                            break;
                        case sf::Keyboard::Return:
                            window.clear(sf::Color::Black);
                            testMap.ClearMap();
                            testMap.GenerateRooms();
                            testMap.DrawMap(window);
                            window.display();
                            break;
                        default:
                            break;
                    }
                        
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        default:
                            break;
                    }
                    break;
                case sf::Event::GainedFocus:
                    window.clear(sf::Color::Black);
                    testMap.DrawMap(window);
                    window.display();
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
