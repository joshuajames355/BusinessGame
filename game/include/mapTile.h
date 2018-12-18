#pragma once
#include <SFML/Graphics.hpp>
#include <textureLoader.h>

enum Biome{tundra, grasslands, desert};

class MapTile
{
public:
	MapTile() = default;
	MapTile(Biome newBiome, TextureLoader* textureLoader);
	void render(sf::RenderWindow* window, float x , float y, float width);
	inline Biome getBiome() { return biome; };
		
private:
	Biome biome;
	sf::Sprite sprite;
};