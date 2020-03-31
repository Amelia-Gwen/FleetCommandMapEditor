#include "InnerMap.h"

#include <fstream>

void InnerMap::load(std::string size)
{
	std::string filename = size + "map.txt";
	std::ifstream reader;
	reader.open(filename);

	tileMap.clear();
	int token;
	while (reader >> token) {
		tileMap.push_back(token);
	}
}
