#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "Stage.h"
#include "Player.h"

using std::function;

class Village : public Stage {
	protected:
		Player player;

		int width;
		int height;

		sf::Texture mapTexture;
		sf::RectangleShape map;

		function<void()> nextStage;

	public:
		Village(const function<void()>& nextStage, const int& width, const int& height);

		void handleEvents(sf::Event& event);
		void render(sf::RenderWindow& window);
};

