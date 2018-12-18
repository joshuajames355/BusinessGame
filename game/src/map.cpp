#include "..\include\map.h"

Map::~Map()
{
}

void Map::generateMap(int newWidth, int newHeight, TextureLoader* textureLoader)
{
	std::cout << "Started Map generation. Map width: " << newHeight << " Height: " << newHeight << std::endl;

	map = new MapTile[newWidth*newHeight];

	width = newWidth;
	height = newHeight;

	srand(time(NULL)); //Seeds rand

	//Generates a list of biomeInfo points randomly
	int NUM_BIOMES = rand() % (width*height / 750) + 3; //The maximun number of biomes is proportional to the size of the map
	std::cout << "Generating " << NUM_BIOMES << " Biomes" << std::endl;
	std::vector<BiomeInfo> biomes;
	biomes.reserve(NUM_BIOMES);
	BiomeInfo newBiome;
	while (biomes.size() < NUM_BIOMES)
	{
		int randomChoice = rand() % 10;
		
		if (randomChoice < 6) newBiome.biomeType = grasslands; //60% of grasslands, 20% desert, 20% tundra
		else if(randomChoice < 8) newBiome.biomeType = tundra;
		else newBiome.biomeType = desert;

		newBiome.x = rand() % width;
		newBiome.y = rand() % height;

		std::cout << "New centre. X: " << newBiome.x << " Y: " << newBiome.y << " Type: " << newBiome.biomeType << std::endl;

		biomes.push_back(newBiome);
	}

	//Makes a map with biomes decided by closest biomeInfo.
	for (int x = 0; x < width; x++)
	{
		//Gets closest biome
		for (int y = 0; y < height; y++)
		{
			Biome closestBiome;
			float closestDist = 900000000000000000000000000.0; //Infinity, measures distance squared
			for (int counter = 0; counter < NUM_BIOMES; counter++)
			{
				float dist = (x - biomes[counter].x)*(x - biomes[counter].x) + (y - biomes[counter].y)*(y - biomes[counter].y);
				if (dist < closestDist )
				{
					closestBiome = biomes[counter].biomeType;
					closestDist = dist;
				}
			}
			map[y*width + x] = MapTile(closestBiome, textureLoader);
		}
	}

	std::cout << "Finished Map gen" << std::endl;
}

MapTile * Map::getMapTile(int x, int y)
{
	return &map[y*width + x];
}

void Map::render(float x, float y, float zoom, sf::RenderWindow * window)
{
	int squareWidth = 32 + zoom*192;
	int squareHeight = squareWidth / 2;
	for (int xCoord = 0; xCoord < width; xCoord++)
	{
		for (int yCoord = 0; yCoord < height; yCoord++)
		{
			if (yCoord % 2 == 0) getMapTile(xCoord, yCoord)->render(window, xCoord*squareWidth + x, yCoord*squareHeight / 2 + y, squareWidth);
			else getMapTile(xCoord, yCoord)->render(window, xCoord*squareWidth + squareWidth/2 + x, yCoord*squareHeight / 2 + y, squareWidth);
		}
	}
}

Map::Map()
{

}
