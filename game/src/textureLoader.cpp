#include "textureLoader.h"

TextureLoader::TextureLoader()
{
	loadImage(grassTile, "grasslandsBase.png");
	loadImage(desertTile, "desertBase.png");
	loadImage(tundraTile, "tundraBase.png");
}

void TextureLoader::loadImage(TextureID textureID, std::string filename)
{
	if (!imageCache[textureID].loadFromFile(filename))
	{
		std::cout << "Error loading file: " << filename << std::endl;
		return;
	}
	std::cout << "Successfully loaded file: " << filename << std::endl;
}
