#pragma once

#include "Model.h"

#include "SFML\Graphics.hpp"

namespace fleet {
	class View {
	public:
		explicit View(const Model& model);

		bool isOpen() { return window.isOpen(); }
	private:
		const Model& model;
		sf::RenderWindow window;
	};
}