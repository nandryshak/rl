#include <memory>
#include <SFML/Graphics.hpp>
#include "global.hpp"

std::unique_ptr<sf::RenderWindow> MainGameWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "Test"));
