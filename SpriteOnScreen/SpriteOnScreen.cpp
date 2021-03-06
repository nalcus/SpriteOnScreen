// SpriteOnScreen.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Nico Nico

#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

	const int gameWidth = 640;
	const int gameHeight = 480;

	// Create the window
	RenderWindow window(VideoMode(gameWidth, gameHeight, 32), "SFML Sprite On Screen Nico Nico ", Style::Titlebar | Style::Close);
	window.setVerticalSyncEnabled(true);

	Texture texture;
	if (!texture.loadFromFile("dork01.png"))
	{
		return EXIT_FAILURE;
	}
	Sprite sprite(texture);
	sprite.setPosition(gameWidth/2, gameHeight/2);
	

	while (window.isOpen())
	{
		// handle the events
		Event event;
		while (window.pollEvent(event))
		{
			// window closed or esc key pressed
			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
			{
				window.close();
				break;
			}
		}

		// clear the window
		window.clear(Color(255, 255, 0));

		sprite.rotate(1);
		window.draw(sprite);

		// display the window
		window.display();

	}


	return EXIT_SUCCESS;
}


