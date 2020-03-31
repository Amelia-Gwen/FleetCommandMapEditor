#pragma once

#include "IScreen.h"

#include "InnerMap.h"
#include "ToolBox.h"

namespace fleet {
	class MapScreen : public IScreen {
	public:
		explicit MapScreen(sf::RenderWindow& window, const sf::Font& font);

		void open(std::string size) { innerMap.load(size); }

		EditorEvent input() override;
		void update() override;
		void draw() override;
	private:
		ToolBox toolBox{ window, font };
		InnerMap innerMap;
	};
}