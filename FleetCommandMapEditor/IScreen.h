#pragma once

#include "EditorEvent.h"

namespace fleet {
	class IScreen {
	public:
		explicit IScreen(sf::RenderWindow& window, const sf::Font& font) : window{ window }, font{ font } {}
		virtual ~IScreen() = default;

		virtual EditorEvent input() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
	protected:
		sf::RenderWindow& window;
		const sf::Font& font;
	};
}