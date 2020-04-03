#include "MapScreen.h"

namespace fleet {
	MapScreen::MapScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		saveButton.setPosition(save_button_x, save_button_y);
		saveButton.setLabelOffset(sf::Vector2f(save_offset_x, save_offset_y));
		resetButton.setPosition(reset_button_x, reset_button_y);
		resetButton.setLabelOffset(sf::Vector2f(reset_offset_x, reset_offset_y));
	}

	void MapScreen::open(std::string size)
	{
		innerMap.setSize(size);
		innerMap.load();
	}

	EditorEvent MapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		EditorEvent editorEvent = toolBox.input();
		if (editorEvent != EditorEvent::None) { return editorEvent; }
		if (saveButton.input(mousePos)) {
			innerMap.save();
			return EditorEvent::ActionComplete;
		}
		if (resetButton.input(mousePos)) {
			innerMap.reset();
			return EditorEvent::ActionComplete;
		}
		if (toolBox.currentSelection() != Selection::None) {
			editorEvent = innerMap.input(toolBox.currentSelection());
		}

		return editorEvent;
	}
	
	void MapScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		toolBox.update();
		saveButton.update(mousePos);
		resetButton.update(mousePos);
		innerMap.update();
	}
	
	void MapScreen::draw()
	{
		window.draw(toolBox);
		window.draw(saveButton);
		window.draw(resetButton);
		window.draw(innerMap);
	}
}