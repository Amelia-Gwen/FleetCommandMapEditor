#pragma once

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

class InnerMap {
public:
	const std::vector<int>& currentMap() const { return tileMap; }

	void setSize(std::string _size) { size = _size; }
	void load();
	void save();
private:
	std::string size;
	std::vector<int> tileMap;
};