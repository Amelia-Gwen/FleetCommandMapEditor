#pragma once

#include "EditorEvent.h"
#include "Expressions.h"
#include "IScreen.h"
#include "Model.h"
#include "Screens.h"

#include "SFML\Graphics.hpp"

#include <unordered_map>

namespace fleet {
	class View {
	public:
		explicit View(const Model& model);

		bool isOpen() const { return window.isOpen(); }
		bool pollEvent(sf::Event& event) { return window.pollEvent(event); }
		void close() { window.close(); }

		IScreen* activeScreen() const { return currentScreen; }

		EditorEvent input();
		void update() { currentScreen->update(); }
		void draw();
	private:
		const Model& model;
		sf::RenderWindow window{ sf::VideoMode(view_width, view_height), "Fleet Command Map Editor" };
		sf::Texture background;
		sf::Sprite backgroundSprite{ background };
		sf::Font font;

		std::unordered_map<std::string, std::unique_ptr<IScreen>> screens;

		IScreen* currentScreen;
		void checkEvent(EditorEvent& editorEvent);
	};
}