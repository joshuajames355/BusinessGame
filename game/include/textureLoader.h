#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <iostream>

enum TextureID{grassTile, desertTile ,NUM_TEXTURES};

class TextureLoader
{
public:
	TextureLoader();
	sf::Texture* getTexture(TextureID textureID) { return &(imageCache[textureID]); };

private:
	std::array<sf::Texture, NUM_TEXTURES> imageCache;
	void loadImage(TextureID textureID, std::string filename);
};