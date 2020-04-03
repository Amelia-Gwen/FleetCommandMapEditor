#include "InnerMap.h"

#include <fstream>

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

void InnerMap::createTileMap()
{
	float tileWidth = 44.f; //FAKE


	for (unsigned i = 0; i < tileValues.size(); ++i) {
		tileMap.emplace_back(sf::RectangleShape(sf::Vector2f()));
		setTileColor(tileMap[i], tileValues[i]);
		// set position
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

void InnerMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& tile : tileMap) {
		target.draw(tile, states);
	}
}
