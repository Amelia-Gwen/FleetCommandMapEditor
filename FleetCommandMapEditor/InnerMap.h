#pragma once

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

class InnerMap {
public:
	void load(std::string size = "small");
private:
	std::vector<int> tileMap;
};