#include "mapTile.h"

MapTile::MapTile(Biome newBiome, TextureLoader* textureLoader)
{
	biome = newBiome;
	sprite.setTexture(*textureLoader->getTexture(grass));
}

void MapTile::render(sf::RenderWindow* window, float x, float y, float width)
{
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(width / sprite.getLocalBounds().width, width / sprite.getLocalBounds().width);
	window->draw(sprite);
}
