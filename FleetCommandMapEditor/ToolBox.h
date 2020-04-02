#pragma once

#include "EditorEvent.h"
#include "GUIButton.h"

#include <SFML\Graphics.hpp>

#include <vector>

namespace fleet {
	class ToolBox : public sf::Drawable {
	public:
		explicit ToolBox(sf::RenderWindow& window);

		EditorEvent input();
		void update();
	private:
		sf::RenderWindow& window;
		std::vector<sf::RectangleShape> tools;

		void initTools();
		void setColor(sf::RectangleShape& tool, int index);
		void setPosition(sf::RectangleShape& tool, int index, sf::Vector2f offset = sf::Vector2f(0.f, 0.f));

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}