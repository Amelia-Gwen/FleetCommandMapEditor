#include "ToolBox.h"

namespace fleet {
	ToolBox::ToolBox(sf::RenderWindow& window) :
		window{ window }
	{
		initTools();
	}

	EditorEvent ToolBox::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		for (int i = 0; i < number_of_tools; ++i) {
			if (tools[i].getGlobalBounds().contains(mousePos)) {
				processSelection(i);
				return EditorEvent::ActionComplete;
			}
		}

		return EditorEvent::None;
	}

	void ToolBox::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		for (auto& tool : tools) {
			if (tool.getGlobalBounds().contains(mousePos)) {
				tool.setOutlineColor(sf::Color::Magenta);
			}
			else {
				tool.setOutlineColor(sf::Color::White);
			}
		}
	}

	void ToolBox::initTools()
	{
		tools.clear();
		for (int i = 0; i < number_of_tools; ++i) {
			tools.emplace_back(sf::RectangleShape(sf::Vector2f(tool_side_length, tool_side_length)));
			setColor(tools[i], i);
			setPosition(tools[i], i);
			tools[i].setOutlineThickness(tool_outline);
		}
	}

	void ToolBox::setColor(sf::RectangleShape& tool, int index)
	{
		switch (index) {
		case 0:
			tool.setFillColor(sf::Color::Blue); // Sea
			break;
		case 1:
			tool.setFillColor(sf::Color::Green); // Forest
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
		float x = (index % 2) * tool_side_length + offset.x * (((index % 2) * 2) + 1);
		float y = (index / 2) * tool_side_length + offset.y * (((index / 2) * 2) + 1);
		tool.setPosition(x, y);
	}

	void ToolBox::processSelection(int index)
	{
		switch (index) {
		case 0:
			if (selection == Selection::Sea) {
				selection = Selection::None;
			}
			else {
				selection = Selection::Sea;
			}
			break;
		case 1:
			if (selection == Selection::Forest) {
				selection = Selection::None;
			}
			else {
				selection = Selection::Forest;
			}
			break;
		case 2:
			if (selection == Selection::Sand) {
				selection = Selection::None;
			}
			else {
				selection = Selection::Sand;
			}
			break;
		case 3:
			if (selection == Selection::Oil) {
				selection = Selection::None;
			}
			else {
				selection = Selection::Oil;
			}
			break;
		case 4:
			if (selection == Selection::Defense) {
				selection = Selection::None;
			}
			else {
				selection = Selection::Defense;
			}
			break;
		case 5:
			if (selection == Selection::Factory) {
				selection = Selection::None;
			}
			else {
				selection = Selection::Factory;
			}
			break;
		default:
			selection = Selection::None;
			break;
		}
	}

	void ToolBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& tool : tools) {
			target.draw(tool, states);
		}
	}
}