#include "main.h"

const int SENSITIVITY = 1;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Business Game");
	TextureLoader textureLoader;

	//Camera positions
	int x = 75;
	int y = 75;

	sf::Vector2i mousePos = sf::Mouse::getPosition();
	sf::Vector2i currentMousePos, difference;

	Map map;
	map.generateMap(50, 50, &textureLoader);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		currentMousePos = sf::Mouse::getPosition();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			difference = currentMousePos - mousePos;
			x += difference.x * SENSITIVITY;
			y += difference.y * SENSITIVITY;
		}

		window.clear(sf::Color::Black);

		map.render(x,y,&window);

		window.display();
		mousePos = currentMousePos;
	}
	return 0;
}
