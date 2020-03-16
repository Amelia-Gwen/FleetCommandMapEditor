#include "NameScreen.h"

namespace fleet {
	NameScreen::NameScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
	}

	EditorEvent NameScreen::input()
	{
		return EditorEvent();
	}
	void NameScreen::update()
	{
	}
	void NameScreen::draw()
	{
	}
}