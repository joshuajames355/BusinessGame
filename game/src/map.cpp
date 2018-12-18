#include "..\include\map.h"

Map::~Map()
{
}

void Map::generateMap(int newWidth, int newHeight, TextureLoader* textureLoader)
{
	map = new MapTile[newWidth*newHeight];

	width = newWidth;
	height = newHeight;

	//Makes an empty map.
	for (int x = 0; x < newWidth*newHeight; x++)
	{
		map[x] = MapTile(grasslands, textureLoader);
	}
}

MapTile * Map::getMapTile(int x, int y)
{
	return &map[y*width + x];
}

void Map::render(float x, float y, sf::RenderWindow * window)
{
	int squareWidth = 128;
	int squareHeight = squareWidth / 2;
	for (int xCoord = 0; xCoord < width; xCoord++)
	{
		for (int yCoord = 0; yCoord < height; yCoord++)
		{
			if (yCoord % 2 == 0) getMapTile(xCoord, yCoord)->render(window, xCoord*squareWidth/2 + x, yCoord*squareHeight / 4 + y, 64);
			else getMapTile(xCoord, yCoord)->render(window, xCoord*squareWidth/2 + squareWidth / 4 + x, yCoord*squareHeight / 4 + y, 64);
		}
	}
}

Map::Map()
{

}
