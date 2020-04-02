#include "InnerMap.h"

#include <fstream>

void InnerMap::setSize(std::string size_)
{
	size = size_;
}

void InnerMap::load()
{
	std::string filename = size + "map.txt";
	std::ifstream reader;
	reader.open(filename);

	tileMap.clear();
	int token;
	while (reader >> token) {
		tileValues.push_back(token);
	}
}

void InnerMap::save()
{
	std::string filename = size + "map.txt";
	std::ofstream writer;
	writer.open(filename);

	for (auto token : tileValues) {
		writer << token << ' ';
	}
}

void InnerMap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& tile : tileMap) {
		target.draw(tile, states);
	}
}
