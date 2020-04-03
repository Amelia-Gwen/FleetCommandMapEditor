#pragma once

namespace fleet {
	constexpr unsigned view_width = 1500u;
	constexpr unsigned view_height = 800u;
	constexpr float view_width_float = static_cast<float>(view_width);
	constexpr float view_height_float = static_cast<float>(view_height);

	// Selection Screen
	constexpr unsigned selection_character_size = 45u;
	constexpr float splash_text_x = 500.f;
	constexpr float splash_text_y = 250.f;
	constexpr float selection_offset_x = 100.f;
	constexpr float selection_offset_y = 20.f;
	constexpr float selection_small_x = 235.f;
	constexpr float selection_large_x = 870.f;
	constexpr float selection_y = 500.f;

	// Tool Box
	constexpr unsigned number_of_tools = 6u;
	constexpr float tool_side_length = 100.f;
	constexpr float tool_outline = 2.f;
	constexpr float tool_outline_hover = 4.f;
	
	// Map Screen

	constexpr float save_button_height = 50.f;
	constexpr float save_button_x = 30.f;
	constexpr float save_button_y = view_height_float - save_button_height - 100.f;
	constexpr float save_button_width = (tool_side_length * 2.f) - (save_button_x * 2.f);
	constexpr float save_offset_x = 40.f;
	constexpr float save_offset_y = 8.f;

	// Inner Map
}