// Mouse position
/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

    cout << "x: " << worldPos.x << ", y: " << worldPos.y<< endl;
}*/

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>

#include "Stage.h"
#include "Start.h"
#include "Village.h"

#include "Player.h"

using namespace std;

int main() {
    // Define game constants
    enum class DefinedStages {
        START,
        VILLAGE,
        FIGHT,
        CREDITS,
    };

    DefinedStages gameStage = DefinedStages::START;

    int width  = 900;
    int height = 500;

    // Init stages
    Start startStage([&]() { gameStage = DefinedStages::VILLAGE; }, width, height);
    Village villageStage([&]() { gameStage = DefinedStages::FIGHT; }, width, height);

    sf::RenderWindow window(sf::VideoMode(width, height), "SFML Pokemon!", sf::Style::Close | sf::Style::Titlebar);

    vector<sf::RectangleShape> zones = {
        sf::RectangleShape(sf::Vector2f(100.0f, 500.0f)),   // enemies 1
        sf::RectangleShape(sf::Vector2f(255.0f, 174.0f)),   // house 1
        sf::RectangleShape(sf::Vector2f(131.0f, 326.0f)),   // enemies 2
        sf::RectangleShape(sf::Vector2f(102.0f, 124.0f)),   // tree 1
        sf::RectangleShape(sf::Vector2f(580.0f, 100.0f)),   // enemies 3
        sf::RectangleShape(sf::Vector2f(262.0f, 261.0f)),   // house 2
        sf::RectangleShape(sf::Vector2f(144.0f, 130.0f)),   // enemies 2
        sf::RectangleShape(sf::Vector2f(133.0f, 131.0f))    // tree 2
    };

    for (size_t i = 0; i < zones.size(); i++) {
        sf::Vector2f size = zones[i].getSize();

        zones[i].setOrigin(size.x / 2, size.y / 2);
    }

    zones[0].setFillColor(sf::Color::Blue);
    zones[1].setFillColor(sf::Color::Red);
    zones[2].setFillColor(sf::Color::Blue);
    zones[3].setFillColor(sf::Color::Red);
    zones[4].setFillColor(sf::Color::Blue);
    zones[5].setFillColor(sf::Color::Red);
    zones[6].setFillColor(sf::Color::Blue);
    zones[7].setFillColor(sf::Color::Red);

    zones[0].setPosition(50, 250);
    zones[1].setPosition(227.5, 87);
    zones[2].setPosition(165.5, 337);
    zones[3].setPosition(291, 330);
    zones[4].setPosition(521, 450);
    zones[5].setPosition(769, 130.5);
    zones[6].setPosition(566, 65);
    zones[7].setPosition(571.5, 195.5);


    // Main Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (gameStage == DefinedStages::VILLAGE) {
                villageStage.handleEvents(event);
            }
        }

        // Render the current gameStage
        switch (gameStage) {
            case DefinedStages::START:
                startStage.render(window);
                break;
            case DefinedStages::VILLAGE:
                villageStage.render(window);
                break;
            case DefinedStages::FIGHT:
                break;
            case DefinedStages::CREDITS:
                break;
            default:
                break;
        }
    }

	return 0;
}
