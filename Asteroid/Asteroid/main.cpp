#pragma once
#include "Asteroid.h"
#include "Ship.h"
#include "GameWrapper.h"
#include <thread>
//#include <iostream>

void garbageCollection(GameWrapper * game)
{
	//game->garbageCollector();
	while (1)
	{
		std::cout << " bitches" << std::endl;
	}
}

int main()
{
	GameWrapper gm;
	void (*foo)(GameWrapper *);
	foo = garbageCollection;

	//std::thread garbageThread(foo, &gm);
	gm.runGame();
	/*
	sf::Texture * pLaserTexture = new sf::Texture();
	sf::Texture * pAsteroidTexture = new sf::Texture();
	pAsteroidTexture->loadFromFile("asteroid-texture.png");

	Asteroid a1(pAsteroidTexture);
	Ship s1;
	List<Asteroid> astList;
	List<Laser> laserList;
	astList.insertAtFront(a1);


	pLaserTexture->loadFromFile("laser-texture.png");
	//Asteroid a2(a1.getBody().getTexture(), a1.getBody().getScale());

	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroid Test.");

	//Laser l1(pLaserTexture, s1.getSlope(), s1.getPos());
	Laser* laserTemp = nullptr;
	bool kp = false, wPressed = false, aPressed = false, dPressed = false; // key pressed bool
	int forwardMotion = 0; // position updater
	int cwRotate = 0;
	sf::Vector2f shipCenter(s1.getPos().x + 18, s1.getPos().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if (event.type == sf::Event::KeyPressed) // key pressed loop from aofallon
			{
				kp = true;
				if (event.key.code == sf::Keyboard::Space)
				{
					laserTemp = new Laser(pLaserTexture, s1.getSlope(), s1.getTip());
					laserTemp->getBody().setRotation(s1.getBody().getRotation());
					laserList.insertAtFront(*laserTemp);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					forwardMotion += 2;
					wPressed = true;
				}
				else
				{
					wPressed = false;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					dPressed = true;
				}
				else
				{
					dPressed = false;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					aPressed = true;
				}
				else
				{
					aPressed = false;
				}
			}
			//if (event.type == sf::Event::KeyPressed)
			//{
			//	kp = true;
			//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			//	{
			//		cwRotate += 5;
			//		
			//	}
			//}
			if (event.type == sf::Event::KeyReleased)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					forwardMotion += 2;
					wPressed = true;
				}
				else
				{
					wPressed = false;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					dPressed = true;
				}
				else
				{
					dPressed = false;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					aPressed = true;
				}
				else
				{
					aPressed = false;
				}
				//kp = false;
			} // end of key stuff borught in
		}

		window.clear();
		if (wPressed)
		{
			s1.move();
		}
		if (dPressed)
		{
			s1.rotateCW();
		}
		if (aPressed)
		{
			s1.rotateCounterCW();
		}
		node<Laser>* pCur = laserList.getHead();
		while (pCur != nullptr) {
			window.draw(pCur->getData().getBody());
			pCur = pCur->getNext();
		}

		

		
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
	delete pLaserTexture; */
		


	return 0;
}