#include "Controller.h"

namespace fleet {
	void Controller::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			view.close();
		}

		sf::Event event;
		EditorEvent editorEvent = EditorEvent::None;
		while (view.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				view.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				editorEvent = view.input();
			}
		}
		processEvent(editorEvent);
	}
	void Controller::processEvent(EditorEvent editorEvent)
	{
		switch (editorEvent)
		{
		case EditorEvent::None:
		default:
			break;
		}
	}
}