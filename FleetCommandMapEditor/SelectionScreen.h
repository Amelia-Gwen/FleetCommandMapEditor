#pragma once

#include "IScreen.h"

#include "GUIButton.h"

#include <SFML\Graphics.hpp>

namespace fleet {
	class SelectionScreen : public IScreen {
	public:
		explicit SelectionScreen(sf::RenderWindow& window, const sf::Font& font);

		EditorEvent input() override;
		void update() override;
		void draw() override;
	private:
		sf::Text splashText{ "Fleet Command Map Editor\n\tSelect Size", font };
		GUIButton smallMapButton{ sf::Vector2f{ 400.f, 100.f}, "20x20 Map", font };
		GUIButton largeMapButton{ sf::Vector2f{ 400.f, 100.f}, "20x40 Map", font };
	};
}