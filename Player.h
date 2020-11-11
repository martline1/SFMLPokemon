#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Player {
	private:
		enum class Directions {
			DOWN = 0,
			LEFT = 1,
			RIGHT = 2,
			UP = 3
		} facing;

		// Movement
		sf::Vector2f toTop    = sf::Vector2f(0.0f, -0.1f);
		sf::Vector2f toBottom = sf::Vector2f(0.0f, 0.1f);
		sf::Vector2f toLeft   = sf::Vector2f(-0.1f, 0.0f);
		sf::Vector2f toRight  = sf::Vector2f(0.1f, 0.0f);

		// Textures
		sf::Texture texture;
		sf::Vector2u elementsInTexture;
		sf::Vector2u offset;
		sf::Vector2u textureSize;

		// Animation
		bool animating;
		sf::IntRect currentImage;
		unsigned currentImageAnimation;
		unsigned imagesPerCicle;
		sf::Clock clock;

	public:
		sf::RectangleShape body;

		Player(sf::Vector2f bodySize, const std::string texturePath, sf::Vector2u elementsInTexture, sf::Vector2u offset, unsigned imagesPerCicle);

		void KeyReleased();

		void animate();
		void update(const int& width, const int& height);

		bool hasCollision();
};
