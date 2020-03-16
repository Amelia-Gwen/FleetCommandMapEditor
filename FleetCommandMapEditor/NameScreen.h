#pragma once

#include "IScreen.h"

#include "EditorEvent.h"

namespace fleet {
	class NameScreen : public IScreen {
	public:
		explicit NameScreen(sf::RenderWindow& window, const sf::Font& font);

		EditorEvent input() override;
		void update() override;
		void draw() override;
	private:
		
	};
}