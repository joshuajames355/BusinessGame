#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"

const int GRID_SIZE = 64;

//pseudo random number generator. For the same x,y,z seed combination, needs to always produce the same number.
float prng(int x, int y, int seed);
float dotGridGradient(int x, int y, int gridX, int gridY, int seed);
float noise(int x, int y, int seed);
sf::Texture debugGenerateTextureFromNoise(int width, int height, int seed);