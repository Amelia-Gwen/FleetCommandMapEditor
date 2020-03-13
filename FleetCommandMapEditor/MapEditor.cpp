#include "MapEditor.h"

void fleet::MapEditor::run()
{
	while (view.isOpen()) {
		controller.input();
		model.update();
		view.update();
		view.draw();
	}
}
