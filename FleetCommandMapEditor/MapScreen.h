#pragma once

#include "IScreen.h"

#include "ToolBox.h"

namespace fleet {
	class MapScreen : public IScreen {
	public:
		explicit MapScreen(sf::RenderWindow& window, const sf::Font& font);

		EditorEvent input() override;
		void update() override;
		void draw() override;
	private:
		ToolBox toolBox{ window, font };
	};
}