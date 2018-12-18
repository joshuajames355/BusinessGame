#pragma once
#include <vector>
#include "mapTile.h"
#include "SFML/Graphics.hpp"
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>
#include <iostream>

class TextureLoader;

struct BiomeInfo
{
	int x;
	int y; //Center of biome
	Biome biomeType;
};

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