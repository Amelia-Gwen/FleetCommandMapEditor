#pragma once

#include "EditorEvent.h"
#include "Selection.h"

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

class InnerMap : public sf::Drawable {
public:
	explicit InnerMap(sf::RenderWindow& window);

	void setSize(std::string size_);
	void load();
	void save();

	EditorEvent input(const Selection& selection);
private:
	sf::RenderWindow& window;
	std::string size;
	std::vector<unsigned> tileValues;
	std::vector<sf::RectangleShape> tileMap;

	void createTileMap();
	void setTileColor(sf::RectangleShape& tile, unsigned value);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};