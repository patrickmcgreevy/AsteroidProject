#pragma once
#include "GameWrapper.h"

#define WINDOW_X 500
#define WINDOW_Y 500

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

	//std::cout << "Asteroid List" << std::endl;
	mAstList.~List();
	//std::cout << "Laser list" << std::endl;
	mLaserList.~List();
}

void GameWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid Game");
	Ship s1;
	Laser* laserTemp = nullptr;

	int nCycles = 0, lastShot = 0, level = 0;

	bool kp = false, wPressed = false, aPressed = false, dPressed = false, spPressed = false; // key pressed bool
	while (window.isOpen())
	{
		++nCycles;

		sf::Event event;
		if (mAstList.getHead() == nullptr)
		{
			refreshLevel(level, mpAstText);
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if (event.type == sf::Event::KeyPressed) // key pressed loop from aofallon
			{
				kp = true;
				//if (event.key.code == sf::Keyboard::Space)
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (!spPressed)
					{
						lastShot = nCycles;
					}
					spPressed = true;

					/*laserTemp = new Laser(mpLaserText, s1.getSlope(), s1.getTip());
					laserTemp->getBody().setRotation(s1.getBody().getRotation());
					mLaserList.insertAtFront(laserTemp);*/
				}
				else
				{
					spPressed = false;
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					spPressed = true;
				}
				else
				{
					//lastShot = nCycles;
					spPressed = false;
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
		if (spPressed && ((nCycles - lastShot) % 100 == 0) || (nCycles - lastShot) == 0)
		{
			//lastShot = nCycles; 
			laserTemp = new Laser(mpLaserText, s1.getSlope(), s1.getBody().getPosition());
			laserTemp->getBody().setRotation(s1.getBody().getRotation());
			mLaserList.insertAtFront(laserTemp);
		}
		// Checks the asteroids and ship for wrap around
		if (nCycles % 100 == 0) {
			astListBoundCheck();
			s1.boundCheck();
		}

		// Check laser bounds
		if (nCycles % 10 == 0)
		{
			node<Laser *> * pCurLaser = mLaserList.getHead(), *pNextLaser;
			while (pCurLaser != nullptr)
			{
				pNextLaser = pCurLaser->getNext();
				if (pCurLaser->getData()->checkRange()) // Allowed range exceeded
				{
					mLaserList.deleteNode(pCurLaser);
				}
				pCurLaser = pNextLaser;
			}
		}

		node<Asteroid *> *pCurA = mAstList.getHead(), *pTempA;
		node<Laser *> *pCurL = mLaserList.getHead(), *pTempL;
		while (pCurA != nullptr)
		{
			// check ship collision
			if (checkCollision(s1, pCurA->getData()))
			{
				// Destroy the ship and decrement lives
				// std::cout << "Ship-Asteroid collisioni." << std::endl;
			}
			pCurL = mLaserList.getHead();
			while (pCurL != nullptr && pCurA != nullptr)
			{
				if (checkCollision(pCurL->getData(), pCurA->getData()))
				{
					if (checkSplit(pCurA->getData()))
					{
						splitAsteroid(pCurA->getData());
					}
					pTempA = pCurA->getNext();
					mAstList.deleteNode(pCurA);
					mLaserList.deleteNode(pCurL);
					pCurA = pTempA;
					pCurL = nullptr;
					mScore.setScore(mScore.getScore() + 1);
				}
				else
				{
					pCurL = pCurL->getNext();
				}
			}
			if (pCurA != nullptr)
			{
				pCurA = pCurA->getNext();
			}
		}

		drawLaserList(window);
		moveLaserList();
		window.draw(mScore.getText());
		drawAsteroidList(window);
		moveAsteroidList();

		window.draw(s1.getBody());

		window.display();
		//++nCycles;
	}
	std::cout << "App ended." << std::endl;
}

void GameWrapper::garbageCollector()
{
	//std::cout << "I am the garbage man!!!" << std::endl;
}

void GameWrapper::refreshLevel(int & n, sf::Texture * pText)
{
	Asteroid * pCur;
	sf::Vector2f v;
	for (int i = 0; i < 6 + n; ++i)
	{
		pCur = new Asteroid(pText);

		if (i % 4 == 0) // Upper left / 4th quadrant
		{
			v.x = 1;
			v.y = 1;
		}
		else if (i % 4 == 1) // Upper right / 1st quadrant
		{
			v.x = WINDOW_WIDTH;
			v.y = 1;
			pCur->getSlope().x = pCur->getSlope().x * -1;
		}
		else if (i % 4 == 2) // Bottom left / 3rd quadrant
		{
			v.x = 1;
			v.y = WINDOW_HEIGHT;
			pCur->getSlope().y = pCur->getSlope().y * -1;
		}
		else // Bottom right / 2nd quadrant
		{
			v.x = WINDOW_WIDTH;
			v.y = WINDOW_HEIGHT;
			pCur->getSlope().x = pCur->getSlope().x * -1;
			pCur->getSlope().y = pCur->getSlope().y * -1;
		}
		/*v.x = 250;
		v.y = 250;*/

		pCur->getBody().setPosition(v);
		mAstList.insertAtFront(pCur);
	}
	++n;
}

// traverses the list and draws each asteroid
void GameWrapper::drawAsteroidList(sf::RenderWindow & w)
{
	node<Asteroid *> *pCur = mAstList.getHead();
	while (pCur != nullptr)
	{ // draw each asteroid as you move through the list
		w.draw(pCur->getData()->getBody());
		//pCur->getData()->move();
		pCur = pCur->getNext();
	}
}

// traverses the list and draws each bullet 
void GameWrapper::drawLaserList(sf::RenderWindow & w) {
	node<Laser *> *pCur = mLaserList.getHead();
	while (pCur != nullptr)
	{ // draw each bullet as you move through
 		w.draw(pCur->getData()->getBody());
		/*for (int i = 0; i < 3; ++i)
		{
			pCur->getData()->move();
		}*/
		pCur = pCur->getNext();
	}
}

// traveses the list and moves each laser
void GameWrapper::moveLaserList() {
	node<Laser *> *pCur = mLaserList.getHead();
	while (pCur != nullptr)
	{ // move each bullet 3 times for a faster speed
		for (int i = 0; i < 3; ++i)
		{
			pCur->getData()->move();
		}
		pCur = pCur->getNext();
	}
}

//traverses the list and moves each asteroid
void GameWrapper::moveAsteroidList() {
	node<Asteroid *> *pCur = mAstList.getHead();
	while (pCur != nullptr)
	{
		pCur->getData()->move();
		pCur = pCur->getNext();
	}
}

double GameWrapper::checkDist(sf::Vector2f & v1, sf::Vector2f & v2)
{
	double d = pow(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2), .5);
	return d;
}

bool GameWrapper::checkCollision(Laser * laser, Asteroid * asteroid) // works
{
	double dist = 0, aTextW = 0, aTextH = 0;
	sf::Vector2f vA, vB;
	vA = laser->getBody().getPosition();
	vB = asteroid->getBody().getPosition();

	//vA.x += 4;
	//vA.y += 10;
	aTextW = asteroid->getBody().getTextureRect().width * asteroid->getBody().getScale().x;
	aTextH = asteroid->getBody().getTextureRect().height * asteroid->getBody().getScale().y;


	vB.x += aTextW/2;
	vB.y += aTextH/2;

	dist = checkDist(vA, vB);
	if (dist > (aTextW / 2))
	//if(abs((vB.x - vA.x)) > (aTextW / 2) || abs((vB.y - vA.y)) > (aTextH / 2))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool GameWrapper::checkCollision(Ship & ship, Asteroid * asteroid)
{
	double dist = 0;
	sf::Vector2f vA, vB;
	vA = ship.getBody().getPosition();
	vB = asteroid->getBody().getPosition();

	vA.x += ship.getBody().getTexture()->getSize().x / 2;
	vA.y += ship.getBody().getTexture()->getSize().y / 2;

	vB.x += asteroid->getBody().getTexture()->getSize().x / 2;
	vB.y += asteroid->getBody().getTexture()->getSize().y / 2;

	dist = checkDist(vA, vB);
	if (dist > asteroid->getBody().getTexture()->getSize().x)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameWrapper::astListBoundCheck() {
	node<Asteroid*>* pCur = mAstList.getHead();
	while (pCur != nullptr) {
		pCur->getData()->boundCheck();
		pCur = pCur->getNext();
	}
}

bool GameWrapper::checkSplit(Asteroid * a)
{
	if (a->getParts() > 0)
	{
		return true;
	}
	return false;
}

void GameWrapper::splitAsteroid(Asteroid * ast)
{
	ast->setParts(ast->getParts() - 1);
	for (int i = 0; i < 2; ++i)
	{
		Asteroid * pNew = new Asteroid(ast->getmText());
		if (pNew != nullptr)
		{
			pNew->getBody().setScale(ast->getBody().getScale().x / 2, ast->getBody().getScale().y / 2);
			pNew->setParts(ast->getParts());
			pNew->getBody().setPosition(ast->getBody().getPosition());
			mAstList.insertAtFront(pNew);
		}
	}
	
}