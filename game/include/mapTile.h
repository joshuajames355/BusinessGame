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
	inline void setBiome(Biome newBiome) { biome = newBiome; };//Only used during mapgen.
		
private:
	Biome biome;
	sf::Sprite sprite;
};

//Returns the textureID to render for a particular biome.
TextureID biomeToTextureID(Biome biome);