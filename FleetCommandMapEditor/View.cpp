#include "View.h"

void fleet::View::draw()
{
	window.clear();
	currentScreen->draw();
	window.display();
}
