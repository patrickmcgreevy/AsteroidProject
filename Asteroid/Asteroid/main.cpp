#pragma once
#include "Asteroid.h"
#include <SFML/Graphics.hpp>
//#include <iostream>

int main()
{
	Asteroid a1;

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100.f);
	
	//system("dir");
	
	shape.setFillColor(sf::Color::Green);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(shape);
		window.draw(a1.getBody());
		a1.getBody().move(a1.getSlope());
		window.display();
	}
	
	return 0;
}