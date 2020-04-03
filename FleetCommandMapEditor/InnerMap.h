#pragma once

#include "EditorEvent.h"
#include "Expressions.h"
#include "Selection.h"

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

namespace fleet {
	class InnerMap : public sf::Drawable {
	public:
		explicit InnerMap(sf::RenderWindow& window);

		void setSize(std::string size_);
		void load();
		void save();
		void reset();

		EditorEvent input(const Selection& selection);
		void update();
	private:
		sf::RenderWindow& window;
		std::string size;
		std::vector<unsigned> tileValues;
		std::vector<sf::RectangleShape> tileMap;

		void createTileMap();
		void setTileColor(sf::RectangleShape& tile, unsigned value);
		void setPosition(sf::RectangleShape& tile, unsigned index, float tileWidth);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}