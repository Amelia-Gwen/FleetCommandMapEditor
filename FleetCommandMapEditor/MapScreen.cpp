#include "MapScreen.h"

namespace fleet {
	MapScreen::MapScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
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
}