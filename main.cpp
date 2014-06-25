// -*- compile-command: "make -k"; -*-
#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
#include "graphictile.hpp"
#include "gametile.hpp"
#include "window.hpp"
#include "global.hpp"

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

    GameWindow gamewindow(screenWidth, screenHeight, "nannyRL", testMap);
    gamewindow.InitializeWindow();

    while (::MainGameWindow->isOpen()) {
        sf::Event event;
        while (::MainGameWindow->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                ::MainGameWindow->close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                case sf::Keyboard::Q:
                    ::MainGameWindow->close();
                    break;
                case sf::Keyboard::Return:
                    gamewindow.RegenerateRooms();
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
                gamewindow.Redraw();
                break;
            default:
                break;
            }
        }
    }

    return 0;
}

