#pragma once

#include "IScreen.h"

#include "Expressions.h"
#include "GUIButton.h"
#include "InnerMap.h"
#include "Selection.h"
#include "ToolBox.h"

#include <SFML\Graphics.hpp>

#include <vector>

namespace fleet {
	class MapScreen : public IScreen {
	public:
		explicit MapScreen(sf::RenderWindow& window, const sf::Font& font);

		void open(std::string size);

		EditorEvent input() override;
		void update() override;
		void draw() override;
	private:
		ToolBox toolBox{ window };
		GUIButton saveButton{ sf::Vector2f(save_button_width, save_button_height), "Save", font };
		GUIButton resetButton{ sf::Vector2f(reset_button_width, reset_button_height), "Reset", font };
		InnerMap innerMap{ window };
		std::vector<sf::RectangleShape> tiles;
	};
}