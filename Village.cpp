#include "Village.h"

Village::Village(const function<void()>& nextStage, const int& width, const int& height)
	: nextStage(nextStage),
	player(sf::Vector2f(64.0f, 64.0f), "textures/characters.png", sf::Vector2u(12, 8), sf::Vector2u(3, 0), 2),
	width(width),
	height(height)
{
	// Position player on map
	player.body.setPosition(428.615f, 44.6f);

	map = sf::RectangleShape(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
	mapTexture.loadFromFile("textures/map.png");

	map.setTexture(&mapTexture);
}

void Village::handleEvents(sf::Event& event) {
    if (event.type == sf::Event::KeyReleased) {
        player.KeyReleased();
    }
}

void Village::render(sf::RenderWindow& window) {
	window.clear();

	window.draw(map);

	player.animate();
	player.update(width, height);

	window.draw(player.body);

	window.display();
}
