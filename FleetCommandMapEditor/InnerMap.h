#pragma once

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

class InnerMap {
public:
	void load(std::string _size);
	void save();
private:
	std::string size;
	std::vector<int> tileMap;
};