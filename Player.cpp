#include "Player.h"

#include <iostream>

using namespace std;

template <typename Enumeration>
auto getValueFromEnum(Enumeration const value)
	-> typename std::underlying_type<Enumeration>::type
{
	return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

Player::Player(sf::Vector2f bodySize, const std::string texturePath, sf::Vector2u elementsInTexture, sf::Vector2u offset, unsigned imagesPerCicle)
	: animating(false),
	facing(Directions::DOWN),
	currentImageAnimation(0),
	imagesPerCicle(imagesPerCicle),
	elementsInTexture(elementsInTexture),
	offset(offset)
{
	// Creating body and adding a texture to it, also 
	// defining the initial values of the internal object state
	body = sf::RectangleShape(bodySize);

	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);

	// Applying texture to the body
	texture.loadFromFile(texturePath);
	body.setTexture(&texture);

	// Defining each element size of the elements in the texture
	textureSize = texture.getSize();

	currentImage.width  = textureSize.x / elementsInTexture.x;
	currentImage.height = textureSize.y / elementsInTexture.y;
}

void Player::KeyReleased() {
	animating = false;
}

void Player::animate() {
	if (clock.getElapsedTime().asSeconds() > 0.3f) {
		if (animating) {
			// Each 0.3 seconds, change image, making an animation effect
			currentImageAnimation = currentImageAnimation >= imagesPerCicle
				? 0
				: currentImageAnimation + 1;
		}

		clock.restart();
	}

	if (animating) {
		currentImage.left = (offset.x + currentImageAnimation) * currentImage.width;
		currentImage.top  = (offset.y + getValueFromEnum(facing)) * currentImage.height;
	}
	else {
		currentImage.left = (offset.x + 1) * currentImage.width;
		currentImage.top  = (offset.y + getValueFromEnum(facing)) * currentImage.height;
	}

	body.setTextureRect(currentImage);
}

void Player::update(const int& width, const int& height) {
	sf::Vector2f size     = body.getSize();
	sf::Vector2f position = body.getPosition();

	// Move player
	// If the player is going out the map, don't move (early return)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		facing = Directions::UP;
		animating = true;

		if (position.y - size.y / 2 <= 0 || hasCollision())
			return;

		body.move(toTop);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		facing = Directions::DOWN;
		animating = true;

		if (position.y + size.y / 2 >= height || hasCollision())
			return;

		body.move(toBottom);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		facing = Directions::LEFT;
		animating = true;

		if (position.x - size.x / 2 <= 0 || hasCollision())
			return;

		body.move(toLeft);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		facing = Directions::RIGHT;
		animating = true;

		if (position.x + size.x / 2 >= width || hasCollision())
			return;

		body.move(toRight);
	}
}

bool Player::hasCollision() {
	sf::Vector2f position = body.getPosition();

	return false;
}
