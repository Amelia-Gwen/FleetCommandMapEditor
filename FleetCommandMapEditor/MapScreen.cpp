#include "MapScreen.h"

namespace fleet {
	MapScreen::MapScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
	}

	void MapScreen::open(std::string size)
	{
		innerMap.setSize(size);
		innerMap.load();
		tiles.clear();
		for (auto tile : innerMap.currentMap()) {
			createTile(tile);
		}
	}

	EditorEvent MapScreen::input()
	{
		return EditorEvent();
	}
	void MapScreen::update()
	{
	}
	void MapScreen::draw()
	{
	}
	void MapScreen::createTile(int token)
	{
		sf::RectangleShape tile;

		switch (token) {
		case 0:
			tile.setFillColor(sf::Color::Blue); // water
			tiles.emplace_back(tile);
			break;
		case 1:
			tile.setFillColor(sf::Color::Green); //trees
			tiles.emplace_back(tile);
			break;
		case 2:
			tile.setFillColor(sf::Color::Yellow); // sand
			tiles.emplace_back(tile);
			break;
		case 3:
			tile.setFillColor(sf::Color::Cyan); // defense structure
			tiles.emplace_back(tile);
			break;
		case 4:
			tile.setFillColor(sf::Color::Black); // oil
			tiles.emplace_back(tile);
			break;
		case 5:
			tile.setFillColor(sf::Color::Magenta); // grass
			tiles.emplace_back(tile);
			break;
		default:
			break;
		}
	}
}