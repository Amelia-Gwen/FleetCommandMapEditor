#pragma once

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

class InnerMap : public sf::Drawable {
public:
	void setSize(std::string size_);
	void load();
	void save();
private:
	std::string size;
	std::vector<int> tileValues;
	std::vector<sf::RectangleShape> tileMap;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};