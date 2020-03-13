#include "View.h"

fleet::View::View(const Model& model) :
	model{ model }
{
}

void fleet::View::draw()
{
	window.clear();
	currentScreen->draw();
	window.display();
}
