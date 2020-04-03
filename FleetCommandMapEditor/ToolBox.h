#pragma once

#include "EditorEvent.h"
#include "Expressions.h"
#include "GUIButton.h"
#include "Selection.h"

#include <SFML\Graphics.hpp>

#include <vector>

namespace fleet {
	class ToolBox : public sf::Drawable {
	public:
		explicit ToolBox(sf::RenderWindow& window);

		Selection currentSelection() const { return selection; }

		EditorEvent input();
		void update();
	private:
		sf::RenderWindow& window;
		std::vector<sf::RectangleShape> tools;
		Selection selection{ Selection::None };

		void initTools();
		void setColor(sf::RectangleShape& tool, unsigned index);
		void setPosition(sf::RectangleShape& tool, unsigned index, sf::Vector2f offset = sf::Vector2f(tile_outline, tile_outline));
		void processSelection(unsigned index);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}