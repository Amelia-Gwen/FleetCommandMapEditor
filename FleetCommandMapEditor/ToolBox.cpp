#include "ToolBox.h"

#include "Expressions.h"

namespace fleet {
	ToolBox::ToolBox(sf::RenderWindow& window) :
		window{ window }
	{
		initTools();
	}

	EditorEvent ToolBox::input()
	{
		return EditorEvent();
	}

	void ToolBox::update()
	{

	}

	void ToolBox::initTools()
	{
		tools.clear();
		for (int i = 0; i < number_of_tools; ++i) {
			tools.emplace_back(sf::RectangleShape(sf::Vector2f(tool_side_length, tool_side_length)));
			setColor(tools[i], i);
			setPosition(tools[i], i);
		}
	}

	void ToolBox::setColor(sf::RectangleShape& tool, int index)
	{
		switch (index) {
		case 0:
			tool.setFillColor(sf::Color::Blue); // Water
			break;
		case 1:
			tool.setFillColor(sf::Color::Green); // Trees
			break;
		case 2:
			tool.setFillColor(sf::Color::Yellow); // Sand
			break;
		case 3:
			tool.setFillColor(sf::Color::Black); // Oil
			break;
		case 4:
			tool.setFillColor(sf::Color::Red); // Defenses
			break;
		case 5:
			tool.setFillColor(sf::Color::Cyan); // Factory
			break;
		default:
			break;
		}
	}

	void ToolBox::setPosition(sf::RectangleShape& tool, int index, sf::Vector2f offset)
	{
		float x = (index % 2) * tool_side_length + offset.x;
		float y = (index / 2) * tool_side_length + offset.y;
		tool.setPosition(x, y);
	}

	void ToolBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& tool : tools) {
			target.draw(tool, states);
		}
	}
}