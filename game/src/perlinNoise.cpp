#include "..\include\perlinNoise.h"

float lerp(float start, float end, float w)
{
	return start + w * (end - start);
}

//Gets the dot product of the distance to a grid cell and the gradient at a grid cell.
float dotGridGradient(int x, int y, int gridX, int gridY, int seed)
{
	const float gradX = prng(gridX, gridY, seed);
	const float gradY = sqrt(1 - gradX * gradX);

	const int dx = x - gridX * GRID_SIZE;
	const int dy = y - gridY * GRID_SIZE;

	return gradX * dx + gradY * dy;
}

float prng(int x, int y, int seed)
{
	int total = x * 987653214 + y * 3592007533 + seed* 608844043; //Both magic numbers are primes.
	total ^= total << 13;
	total ^= total >> 17;
	total ^= total << 5;
	return (total % 10000000) / 10000000.0f;
}

float noise(int x, int y, int seed)
{
	//Grid coordinates
	int x0 = x / GRID_SIZE;
	int x1 = x0 + 1;
	int y0 = y / GRID_SIZE;
	int y1 = y0 + 1;

	float sx = (float)x/(float)GRID_SIZE - x0;
	float sy = (float)y/(float)GRID_SIZE - y0;

	float n0 = dotGridGradient(x, y, x0, y0, seed);
	float n1 = dotGridGradient(x, y, x1, y0, seed);
	float ix0 = lerp(n0, n1, sx);
	n0 = dotGridGradient(x, y, x0, y1, seed);
	n1 = dotGridGradient(x, y, x1, y1, seed);
	float ix1 = lerp(n0, n1, sx);

	return lerp(ix0, ix1, sy);
}

sf::Texture debugGenerateTextureFromNoise(int width, int height, int seed)
{
	sf::Texture tex;
	tex.create(width, height);
	sf::Uint8* pixels = new sf::Uint8[width * height * 4];
	int counter = 0;
	while (counter < width * height * 4)
	{
		float perlinValue = noise((counter/4) % width, (counter/4) / width, seed) *128 + 128;
		pixels[counter] = perlinValue;
		pixels[counter + 1] = perlinValue;
		pixels[counter + 2] = perlinValue;
		pixels[counter + 3] = 255;
		counter += 4;
	}
	tex.update(pixels);
	return tex;
}
