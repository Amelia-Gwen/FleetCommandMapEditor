#pragma once

namespace fleet {
	class IScreen {
	public:
		virtual void update() = 0;
		virtual void draw() = 0;
	private:
	};
}