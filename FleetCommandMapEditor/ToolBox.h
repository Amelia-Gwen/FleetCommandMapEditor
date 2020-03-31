#pragma once

#include "EditorEvent.h"
#include "GUIButton.h"

#include <SFML\Graphics.hpp>

#include <vector>

namespace fleet {
	class ToolBox : public sf::Drawable {
	public:
		explicit ToolBox(sf::RenderWindow& window, const sf::Font& font);

		EditorEvent input();
		void update();
		void draw();
	private:
		sf::RenderWindow& window;
		const sf::Font& font;
		std::vector<sf::RectangleShape> tools;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}