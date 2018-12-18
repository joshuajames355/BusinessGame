#include "main.h"

const int SENSITIVITY = 1;
const float ZOOM_SENSITIVITY = 0.05;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Business Game");
	TextureLoader textureLoader;

	//Camera positions
	int x = 150;
	int y = 150;
	float zoom = 0.5;

	sf::Vector2i mousePos = sf::Mouse::getPosition();
	sf::Vector2i currentMousePos, difference;

	Map map;
	map.generateMap(100, 150, &textureLoader);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				{
					zoom = std::min(1.0f, std::max(0.0f, zoom + event.mouseWheelScroll.delta * ZOOM_SENSITIVITY));
				}
			}
		}


		currentMousePos = sf::Mouse::getPosition();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			difference = currentMousePos - mousePos;
			x += difference.x * SENSITIVITY;
			y += difference.y * SENSITIVITY;
		}

		window.clear(sf::Color::Black);

		map.render(x,y,zoom,&window);

		window.display();
		mousePos = currentMousePos;
	}
	return 0;
}
