#include "Start.h"

#include <iostream>

using std::cout;
using std::endl;

Start::Start(const function<void()>& nextStage, const int &width, const int &height) : nextStage(nextStage) {
	logo = sf::RectangleShape(sf::Vector2f(300.0f, 300.0f));
	veil = sf::RectangleShape(sf::Vector2f(300.0f, 300.0f));

	// Apply texture
	logoTexture.loadFromFile("textures/logo.png");
	logo.setTexture(&logoTexture);

	// Center both, logo and veil
	logo.setOrigin(logo.getSize().x / 2, logo.getSize().y / 2);
	veil.setOrigin(logo.getSize().x / 2, logo.getSize().y / 2);

	logo.setPosition(width / 2, height / 2);
	veil.setPosition(width / 2, height / 2);

	veil.setFillColor(sf::Color(35, 35, 35, 255));
}

void Start::render(sf::RenderWindow& window) {
	window.clear(logoBackgroundColor);

	window.draw(logo);

	if (veilAlphaColor > 0 && !unMounting) {
		if (clock.getElapsedTime().asSeconds() > 0.02) {
			// Discovering logo
			veil.setFillColor(sf::Color(35, 35, 35, veilAlphaColor--));

			clock.restart();
		}
	}
	else {
		unMounting = true;
	
		if (clock.getElapsedTime().asSeconds() > 0.007) {
			if (veilAlphaColor < 255) {
				// Covering logo
				veil.setFillColor(sf::Color(35, 35, 35, veilAlphaColor++));
			}
			else {
				nextStage();
			}

			clock.restart();
		}
	}

	window.draw(veil);

	window.display();
}
