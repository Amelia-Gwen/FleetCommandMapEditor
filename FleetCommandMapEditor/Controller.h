#pragma once

#include "Model.h"
#include "View.h"
#include "EditorEvent.h"

namespace fleet {
	class Controller {
	public:
		explicit Controller(View& view, Model& model) : view{ view }, model{ model } {}

		void input();
	private:
		View& view;
		Model& model;

		void processEvent(EditorEvent editorEvent);
	};
}