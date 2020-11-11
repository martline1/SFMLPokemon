#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "Stage.h"

using std::function;

class Start : public Stage {
	protected:
		sf::Texture logoTexture;
		sf::RectangleShape logo;
		sf::RectangleShape veil;

		sf::Color logoBackgroundColor = sf::Color(35, 35, 35);

		sf::Clock clock;

		int veilAlphaColor = 255;
		bool unMounting    = false;

		function<void()> nextStage;

	public:
		Start(const function<void()> &nextStage, const int& width, const int& height);

		void render(sf::RenderWindow& window);
};

