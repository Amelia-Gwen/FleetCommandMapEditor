#include "SelectionScreen.h"

#include "Expressions.h"

namespace fleet {
	SelectionScreen::SelectionScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		splashText.setPosition(splash_text_x, splash_text_y);
		splashText.setCharacterSize(selection_character_size);
		splashText.setFillColor(sf::Color::Magenta);
		smallMapButton.setLabelOffset(sf::Vector2f(selection_offset_x, selection_offset_y));
		smallMapButton.setPosition(selection_small_x, selection_y);
		smallMapButton.setCharacterSize(selection_character_size);
		largeMapButton.setLabelOffset(sf::Vector2f(selection_offset_x, selection_offset_y));
		largeMapButton.setPosition(selection_large_x, selection_y);
		largeMapButton.setCharacterSize(selection_character_size);
	}

	EditorEvent SelectionScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (smallMapButton.input(mousePos)) {
			return EditorEvent::OpenSmall;
		}
		else if (largeMapButton.input(mousePos)) {
			return EditorEvent::OpenLarge;
		}

		return EditorEvent::None;
	}
	void SelectionScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		smallMapButton.update(mousePos);
		largeMapButton.update(mousePos);
	}
	void SelectionScreen::draw()
	{
		window.draw(splashText);
		window.draw(smallMapButton);
		window.draw(largeMapButton);
	}
}