#pragma once

#include <SFML/Graphics.hpp>


class Stage {
	public:
		/**
		 * Used to define events specific to this very stage
		 */
		void handleEvents(sf::Event& event) {};

		/**
		 * Called every frame, is used to define the whole implementation
		 * of the stage
		 */
		virtual void render(sf::RenderWindow& window) = 0;
};
