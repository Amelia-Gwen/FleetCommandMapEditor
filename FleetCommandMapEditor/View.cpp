#include "View.h"

namespace fleet {
	View::View(const Model& model) :
		model{ model }
	{
		window.setFramerateLimit(60);
		//background.loadFromFile("Assets/background.png");
		font.loadFromFile("a-song-for-jennifer/a-song-for-jennifer.ttf");

		screens.emplace(std::make_pair("Selection Screen", std::make_unique<SelectionScreen>(window, font)));

		currentScreen = screens["Selection Screen"].get();
	}

	void View::draw()
	{
		window.clear();
		currentScreen->draw();
		window.display();
	}

	EditorEvent View::input()
	{
		EditorEvent editorEvent = currentScreen->input();
		checkEvent(editorEvent);
		return editorEvent;
	}

	void View::draw()
	{
		window.clear();
		window.draw(backgroundSprite);
		currentScreen->draw();
		window.display();
	}
}