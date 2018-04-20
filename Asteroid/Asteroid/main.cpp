#pragma once
#include "Asteroid.h"
#include "Ship.h"
#include "Laser.h"
#include "List.h"
#include <SFML/Graphics.hpp>
//#include <iostream>

int main()
{
	sf::Texture * pLaserTexture = new sf::Texture();
	sf::Texture * pAsteroidTexture = new sf::Texture();
	pAsteroidTexture->loadFromFile("asteroid-texture.png");

	Asteroid a1(pAsteroidTexture);
	Ship s1;
	List<Asteroid> astList;
	
	astList.insertAtFront(a1);


	pLaserTexture->loadFromFile("laser-texture.png");
	//Asteroid a2(a1.getBody().getTexture(), a1.getBody().getScale());

	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroid Test.");

	Laser l1(pLaserTexture, s1.getSlope(), s1.getPos());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		l1.move();

		window.draw(l1.getBody());
		window.draw(a1.getBody());
		window.draw(s1.getBody());

		a1.getBody().move(a1.getSlope());
		s1.rotateCW();
		s1.move();
		window.display();
	}
	
	delete pAsteroidTexture;
	delete pLaserTexture;

	return 0;
}