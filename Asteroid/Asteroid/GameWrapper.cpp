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
	Ship pShip();

	/*refreshLevel(0, mpAstText);

	drawAsteroidList(window);
	window.display();
	system("pause");*/
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