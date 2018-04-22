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

	bool kp = false; // key pressed bool
	int forwardMotion = 0; // position updater
	int cwRotate = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) // key pressed loop from aofallon
			{
				kp = true;
				if (event.key.code == sf::Keyboard::W)
				{
					forwardMotion += 5;
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				kp = true;
				if (event.key.code == sf::Keyboard::A)
				{
					cwRotate += 1;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				kp = false;
				s1.move();
			} // end of key stuff borught in
		}

		window.clear();

		for (int i = 0; i < forwardMotion; i++)
			s1.move();
		for (int i = 0; i < cwRotate; i++)
			s1.rotateCW();
		l1.move();

		window.draw(l1.getBody());
		window.draw(a1.getBody());
		window.draw(s1.getBody());

		a1.getBody().move(a1.getSlope());
		//s1.rotateCW();
		//s1.move();
		window.display();
		forwardMotion = 0;
		cwRotate = 0;
	}
	
	delete pAsteroidTexture;
	delete pLaserTexture;

	return 0;
}