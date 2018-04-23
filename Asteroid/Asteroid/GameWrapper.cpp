#pragma once
#include "GameWrapper.h"

GameWrapper::GameWrapper()
{
	mpAstText = new sf::Texture();
	mpAstText->loadFromFile("asteroid-texture.png");

	mpLaserText = new sf::Texture();
	mpLaserText->loadFromFile("laster-texture.png");

	mpBorderText = new sf::Texture();
	mpBorderText->loadFromFile("border-texture.png");
}

GameWrapper::~GameWrapper()
{
	delete mpAstText;
	delete mpLaserText;
	delete mpBorderText;
}

void GameWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroid Game");
	Ship s1;
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
					l2 = new Laser(mpLaserText, s1.getSlope(), s1.getTip());
					l2->getBody().setRotation(s1.getBody().getRotation());
				}
				if (event.key.code == sf::Keyboard::X)
				{
					l2->move();
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
		if (l2 != nullptr) {
			l2->move();
			window.draw(l2->getBody());
		}
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


		/*for (int i = 0; i < forwardMotion; i++)
		s1.move();
		for (int i = 0; i < cwRotate; i++)
		s1.rotateCW()*/;
		l1.move();

		window.draw(l1.getBody());

		window.draw(a1.getBody());
		window.draw(s1.getBody());

		a1.getBody().move(a1.getSlope());
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

void GameWrapper::drawAsteroidList(sf::RenderWindow & w)
{
	node<Asteroid *> *pCur = mAstList.getHead();
	while (pCur != nullptr)
	{
		w.draw(pCur->getData()->getBody());
		pCur = pCur->getNext();
	}
}

bool checkCollision(Laser * laser, Asteroid * asteroid)
{

}
bool checkCollision(Ship * ship, Asteroid * asteroid);