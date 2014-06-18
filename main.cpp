// -*- compile-command: "make -k"; -*-
#include <SFML/Graphics.hpp>
#include <iostream>

int rand256()
{
    int num = rand() % 256;
    return num;
}

int main()
{
    int height = 24;
    int width = height / 3 * 2;
    int charsWide = 80;
    int charsTall = 24;

    int screenWidth = width * charsWide;
    int screenHeight = height * charsTall;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "nannyRL",
                            sf::Style::Titlebar | sf::Style::Close);

    

    sf::Font font;
    font.loadFromFile("DroidSansMono.ttf");
    char randChar = 0;
    sf::Text text(randChar, font, 24);

    int min = 33;
    int max = 126;

    for (int ypos = 0; ypos < screenHeight - height; ypos += height) {
        for (int xpos = 0; xpos < screenWidth - width; xpos += width) {
            randChar = rand() % (max - min + 1) + min;
            text.setString(randChar);
            text.setPosition(xpos, ypos);
            sf::Color color(rand256(), rand256(), rand256());
            text.setColor(color);
            window.draw(text);
        }
    }

    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

    }
}
