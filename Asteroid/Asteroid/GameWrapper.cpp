#pragma once
#include "GameWrapper.h"

GameWrapper::GameWrapper()
{
	//loads the textures for the member sprites
	mpAstText = new sf::Texture();
	mpAstText->loadFromFile("asteroid-texture.png");

	mpLaserText = new sf::Texture();
	mpLaserText->loadFromFile("laser-texture.png");

	mpBorderText = new sf::Texture();
	mpBorderText->loadFromFile("border-texture.png");
}

GameWrapper::~GameWrapper()
{
	//deletes the textures
	delete mpAstText;
	delete mpLaserText;
	delete mpBorderText;
}

void GameWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroid Game");
	Ship s1;
	Laser* laserTemp = nullptr;

	bool kp = false, wPressed = false, aPressed = false, dPressed = false; // key pressed bool

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
					laserTemp = new Laser(mpLaserText, s1.getSlope(), s1.getTip());
					laserTemp->getBody().setRotation(s1.getBody().getRotation());
					mLaserList.insertAtFront(laserTemp);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
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

			if (event.type == sf::Event::KeyReleased)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
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


		drawLaserList(window);
		moveLaserList();

		/*for (int i = 0; i < forwardMotion; i++)
		s1.move();
		for (int i = 0; i < cwRotate; i++)
		s1.rotateCW()*/

		
		window.draw(s1.getBody());

		//s1.rotateCW();
		//s1.move();
		window.display();
	
	}
}

void GameWrapper::refreshLevel(int n, sf::Texture * pText)
{
	Asteroid * pCur;
	sf::Vector2f v;
	for (int i = 0; i < 4 + n; ++i)
	{
		pCur = new Asteroid(pText);

		if (i % 4 == 0)
		{
			v.x = 1;
			v.y = 1;
		}
		else if (i % 4 == 1)
		{
			v.x = 499;
			v.y = 1;
		}
		else if (i % 4 == 2)
		{
			v.x = 1;
			v.y = 499;
		}
		else
		{
			v.x = 499;
			v.y = 499;
		}

		pCur->getBody().setPosition(v);
		mAstList.insertAtFront(pCur);
	}
}

// traverses the list and draws each asteroid
void GameWrapper::drawAsteroidList(sf::RenderWindow & w)
{
	node<Asteroid *> *pCur = mAstList.getHead();
	while (pCur != nullptr)
	{ // draw each asteroid as you move through the list
		w.draw(pCur->getData()->getBody());
		pCur = pCur->getNext();
	}
}

// traverses the list and draws each bullet 
void GameWrapper::drawLaserList(sf::RenderWindow & w) {
	node<Laser *> *pCur = mLaserList.getHead();
	while (pCur != nullptr)
	{ // draw each bullet as you move through
		w.draw(pCur->getData()->getBody());
		pCur = pCur->getNext();
	}
}

// traveses the list and moves each laser
void GameWrapper::moveLaserList() {
	node<Laser *> *pCur = mLaserList.getHead();
	while (pCur != nullptr)
	{ // move each bullet 3 times for a faster speed
		pCur->getData()->move();
		pCur->getData()->move();
		pCur->getData()->move();
		pCur = pCur->getNext();
	}
}

//traverses the list and moves each asteroid
void GameWrapper::moveAsteroidList() { // dosent work yet
	node<Asteroid *> *pCur = mAstList.getHead();
	while (pCur != nullptr)
	{
		//pCur->getData()->move();
		pCur = pCur->getNext();
	}
}