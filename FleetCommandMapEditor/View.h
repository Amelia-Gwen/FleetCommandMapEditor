#pragma once

#include "Expressions.h"
#include "IScreen.h"
#include "Model.h"

#include "SFML\Graphics.hpp"

namespace fleet {
	class View {
	public:
		explicit View(const Model& model);

		bool isOpen() const { return window.isOpen(); }

		void update() { currentScreen->update(); }
		void draw();
	private:
		const Model& model;
		sf::RenderWindow window{ sf::VideoMode(view_width, view_height), "Fleet Command Map Editor" };

		IScreen* currentScreen;
	};
}