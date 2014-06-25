// -*- compile-command: "make -k"; -*-
#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
#include "graphictile.hpp"
#include "gametile.hpp"
#include "window.hpp"

std::unique_ptr<sf::RenderWindow> window;

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
    // window(new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "nannyRL",
    //        sf::Style::Titlebar | sf::Style::Close));
    std::unique_ptr<sf::RenderWindow> window( new sf::RenderWindow( sf::VideoMode(screenWidth, screenHeight), "Test"));

    // window.clear();
    // window.display();

    GameWindow gamewindow(screenWidth, screenHeight, "nannyRL", testMap);
    gamewindow.InitializeWindow();

    std::cout << "isOpen()? " << window->isOpen() << std::endl;

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                case sf::Keyboard::Q:
                    window->close();
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

    std::cout << gamewindow << std::endl;
    return 0;
}

