#include "View.h"

namespace fleet {
	View::View(const Model& model) :
		model{ model }
	{
		window.setFramerateLimit(60);
		//background.loadFromFile("Assets/background.png");
		font.loadFromFile("a-song-for-jennifer/a-song-for-jennifer.ttf");

		screens.emplace(std::make_pair("Selection Screen", std::make_unique<SelectionScreen>(window, font)));
		screens.emplace(std::make_pair("Map Screen", std::make_unique<MapScreen>(window, font)));

		currentScreen = screens["Selection Screen"].get();
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
	void View::checkEvent(EditorEvent& editorEvent)
	{
		switch (editorEvent)
		{
		case EditorEvent::OpenSmall:
			currentScreen = screens["Map Screen"].get();
			dynamic_cast<MapScreen*>(currentScreen)->open("small");
			break;
		case EditorEvent::OpenLarge:
			currentScreen = screens["Map Screen"].get();
			dynamic_cast<MapScreen*>(currentScreen)->open("large");
			break;
		case EditorEvent::None:
		default:
			break;
		}
	}
}