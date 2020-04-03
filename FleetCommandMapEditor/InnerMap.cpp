#include "InnerMap.h"

#include <fstream>

namespace fleet {
	InnerMap::InnerMap(sf::RenderWindow & window) :
		window{ window }
	{
	}

	void InnerMap::setSize(std::string size_)
	{
		size = size_;
	}

	void InnerMap::load()
	{
		std::string filename = size + "map.txt";
		std::ifstream reader;
		reader.open(filename);

		tileMap.clear();
		int token;
		while (reader >> token) {
			tileValues.push_back(token);
		}

		createTileMap();
	}

	void InnerMap::save()
	{
		std::string filename = size + "map.txt";
		std::ofstream writer;
		writer.open(filename);

		for (auto token : tileValues) {
			writer << token << ' ';
		}
	}

	void InnerMap::reset()
	{
		for (auto& value : tileValues) {
			value = 0;
		}
		for (auto& tile : tileMap) {
			tile.setFillColor(sf::Color::Blue);
		}
	}

	EditorEvent InnerMap::input(const Selection& selection)
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };
		unsigned value = static_cast<unsigned>(selection);

		for (unsigned i = 0; i < tileMap.size(); ++i) {
			if (tileMap[i].getGlobalBounds().contains(mousePos)) {
				tileValues[i] = value;
				setTileColor(tileMap[i], value);
				return EditorEvent::ActionComplete;
			}
		}

		return EditorEvent::None;
	}

	void InnerMap::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		for (auto& tile : tileMap) {
			if (tile.getGlobalBounds().contains(mousePos)) {
				tile.setOutlineColor(sf::Color::Magenta);
			}
			else {
				tile.setOutlineColor(sf::Color::White);
			}
		}
	}

	void InnerMap::createTileMap()
	{
		float tileWidth;
		if (size == "small") {
			tileWidth = ((view_width_float - inner_map_origin_x) / 20.f) - (tile_outline * 2.f);
		}
		else {
			tileWidth = ((view_width_float - inner_map_origin_x) / 40.f) - (tile_outline * 2.f);
		}

		for (unsigned i = 0; i < tileValues.size(); ++i) {
			tileMap.emplace_back(sf::RectangleShape(sf::Vector2f(tileWidth, tile_height)));
			tileMap[i].setOutlineThickness(tile_outline);
			tileMap[i].setOutlineColor(sf::Color::White);
			setTileColor(tileMap[i], tileValues[i]);
			setPosition(tileMap[i], i, tileWidth);
		}
	}

	void InnerMap::setTileColor(sf::RectangleShape& tile, unsigned value)
	{
		switch (value) {
		case 0:
			tile.setFillColor(sf::Color::Blue);
			break;
		case 1:
			tile.setFillColor(sf::Color::Green);
			break;
		case 2:
			tile.setFillColor(sf::Color::Yellow);
			break;
		case 3:
			tile.setFillColor(sf::Color::Black);
			break;
		case 4:
			tile.setFillColor(sf::Color::Red);
			break;
		case 5:
			tile.setFillColor(sf::Color::Cyan);
			break;
		default:
			break;
		}
	}

	void InnerMap::setPosition(sf::RectangleShape& tile, unsigned index, float tileWidth)
	{
		int tileNum;
		if (size == "small") {
			tileNum = 20;
		}
		else {
			tileNum = 40;
		}
		float x = inner_map_origin_x + (index % tileNum) * tileWidth + (tile_outline * 2) * (index % tileNum);
		float y = inner_map_origin_y + (index / tileNum) * tile_height + (tile_outline * 2) * (index / tileNum);

		tile.setPosition(x, y);
	}

	void InnerMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& tile : tileMap) {
			target.draw(tile, states);
		}
	}
}
