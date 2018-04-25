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

	mAstList.~List();
	mLaserList.~List();
}

void GameWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid Game");
	Ship s1;
	Laser* laserTemp = nullptr;
	window.requestFocus();
	int nCycles = 0, lastShot = 0, level = 0, sheildTimer = 0;

	bool kp = false, wPressed = false, aPressed = false, dPressed = false, spPressed = false; // key pressed bool
	mScore.setScore(0);
	mScore.setLives(3);
	mAstList.~List();
	mLaserList.~List();
	while (window.isOpen())
	{
		while (!window.hasFocus())
		{

		}
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
			else if (event.type == sf::Event::KeyPressed)
			{
				kp = true;
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (!spPressed)
					{
						lastShot = nCycles;
					}
					spPressed = true;
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
			laserTemp = new Laser(mpLaserText, s1.getSlope(), s1.getBody().getPosition());
			laserTemp->getBody().setRotation(s1.getBody().getRotation());
			mLaserList.insertAtFront(laserTemp);
		}

		if (mScore.getLives() <= 0) {
			window.close();
			std::cout << "GAME OVER\nFinal Score : " << mScore.getScore() << "\n\n";
			
		}
		// Checks the asteroids and ship for wrap around every 100 cycles
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
			if (checkCollision(s1, pCurA->getData()) && sheildTimer > 1000)
			{
				mScore.setLives(mScore.getLives()- 1);
				sheildTimer = 0;
				// Destroy the ship and decrement lives
			}
			pCurL = mLaserList.getHead(); // sets the current laser to the head laser
			while (pCurL != nullptr && pCurA != nullptr)
			{
				if (checkCollision(pCurL->getData(), pCurA->getData()))
				{
					if (checkSplit(pCurA->getData()))
					{
						splitAsteroid(pCurA->getData());
					}
					pTempA = pCurA->getNext(); // Temp is set to the next asteroid
					mAstList.deleteNode(pCurA); // The current asteroid is deleted
					mLaserList.deleteNode(pCurL); // The destroying laser is deleted
					pCurA = pTempA; // the current asteroid becomes the temporary asteroid
					pCurL = nullptr; // current laser is set to nullptr so that every laser is checked against the new current asteroid
					mScore.setScore(mScore.getScore() + 1); // increments score
				}
				else
				{
					pCurL = pCurL->getNext(); // moves the laser to the next position
				}
			}
			if (pCurA != nullptr)
			{
				pCurA = pCurA->getNext(); // moves to the next asteroid if it isn't at the end of the list
			}
		}

		drawLaserList(window); // Draws all lasers
		moveLaserList(); // moves all lasers
		window.draw(mScore.getText()); // draws the score
		drawAsteroidList(window); // draws all the asteroids
		moveAsteroidList(); // moves all the asteroids

		window.draw(s1.getBody()); // draws teh ship's sprite

		window.display(); // displays what has been printed to the window
		++sheildTimer;
	}
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

	aTextW = asteroid->getBody().getTextureRect().width * asteroid->getBody().getScale().x;
	aTextH = asteroid->getBody().getTextureRect().height * asteroid->getBody().getScale().y;


	vB.x += aTextW/2;
	vB.y += aTextH/2;

	dist = checkDist(vA, vB);
	if (dist > (aTextW / 2)) // checks if the distance between the points is less than the radius of the asteroid sprite
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

	vA.x += ship.getBody().getTexture()->getSize().x / 2; // adds to x and y the radius of the sprite texture
	vA.y += ship.getBody().getTexture()->getSize().y / 2;

	vB.x += (asteroid->getBody().getTexture()->getSize().x * asteroid->getBody().getScale().x) / 2; // adds to x the radius of the asteroid sprite
	vB.y += (asteroid->getBody().getTexture()->getSize().y * asteroid->getBody().getScale().y) / 2; // ands to y the radius of the asteroid sprite

	dist = checkDist(vA, vB);
	if (dist > asteroid->getBody().getTexture()->getSize().x / 3)
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
		pCur->getData()->boundCheck(); // corrects for the bounds
		pCur = pCur->getNext();
	}
}

bool GameWrapper::checkSplit(Asteroid * a) // checks if the asteroid may be split
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
	for (int i = 0; i < 2; ++i) // Adds two smaller asteroids to the asteroid list
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

void GameWrapper::mainMenu() {
	int sel = 0;
	char c;
	bool run = true;
	do {
		std::cout << "Welcome to Asteroids++" << std::endl << "Would you like to...\n\n" << "1 : Play game\n2 : See instruction\n3 : Exit\n";
		do {
			std::cin >> c;
		} while (c != '1' && c != '2' && c != '3');
		if (c == '1') {
			system("cls");
			this->runGame();
		}
		else if (c == '2') {
			system("cls");
			printInstructions();
		}
		else if (c == '3')
		{
			run = false;
		}
	} while (run);
	return;
}

void GameWrapper::printInstructions() {
	std::cout << "Instructions\nObjective: Shoot asteroids to score. Avoid asteroids to not die\n\nControls:\n\nMove Forward : W\nRotate right/left : A/d\nShoot : Space\n\n\n";
}