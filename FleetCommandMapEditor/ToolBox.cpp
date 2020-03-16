#include "ToolBox.h"

namespace fleet {
	ToolBox::ToolBox(sf::RenderWindow& window, const sf::Font& font) :
		window{ window },
		font{ font }
	{
	}

	EditorEvent ToolBox::input()
	{
		return EditorEvent();
	}
	void ToolBox::update()
	{
	}
	void ToolBox::draw()
	{
	}

	void ToolBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
}