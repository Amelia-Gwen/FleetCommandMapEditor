#pragma once

#include "IScreen.h"

namespace fleet {
	class SelectionScreen : public IScreen {
	public:
		SelectionScreen(sf::RenderWindow& window, const sf::Font& font) : IScreen{ window, font } {}


	private:
	};
}