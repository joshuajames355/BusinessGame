#include "mapTile.h"

MapTile::MapTile(Biome newBiome, TextureLoader* textureLoader)
{
	biome = newBiome;
	sprite.setTexture(*textureLoader->getTexture(biomeToTextureID(biome)));
}

void MapTile::render(sf::RenderWindow* window, float x, float y, float width)
{
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(width / sprite.getLocalBounds().width, width / sprite.getLocalBounds().width);
	window->draw(sprite);
}

TextureID biomeToTextureID(Biome biome)
{
	switch (biome)
	{
	case tundra:
		return grassTile; //Not implemented
		break;
	case grasslands:
		return grassTile;
		break;
	case desert:
		return desertTile;
		break;
	default:
		break;
	}
}
