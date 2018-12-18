#pragma once
#include <array>
#include "mapTile.h"
#include "SFML/Graphics.hpp"

class TextureLoader;

class Map
{
public:
	Map();
	~Map();
	void generateMap(int newWidth, int newHeight, TextureLoader* textureLoader);
	MapTile* getMapTile(int x, int y);
	void render(float x, float y, sf::RenderWindow* window); //x and y are camera positions.


private:
	int height;
	int width;
	MapTile *map;
};