#pragma once
#include "Asteroid.h"
#include "Ship.h"
#include <SFML/Graphics.hpp>
//#include <iostream>

int main()
{
	Asteroid a1;
	Ship s1;

	//Asteroid a2(a1.getBody().getTexture(), a1.getBody().getScale());

	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroid Test.");
	sf::CircleShape shape(100.f);
	std::cout << "yo";
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
		window.draw(s1.getBody());
		//window.draw(a2.getBody());
		a1.getBody().move(a1.getSlope());
		s1.rotateCW();
		window.display();
	}
	
	return 0;
}