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
		window.draw(toolBox);
		window.draw(innerMap);
	}
}