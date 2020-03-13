#pragma once

#include "Model.h"
#include "View.h"

namespace fleet {
	class Controller {
	public:
		explicit Controller(const View& view, Model& model) : view{ view }, model{ model } {}

		void input();
	private:
		const View& view;
		Model& model;
	};
}