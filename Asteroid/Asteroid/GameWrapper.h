#pragma once
#include "Asteroid.h"
#include "Laser.h"
#include "Ship.h"
#include "List.h"

class GameWrapper
{
public:
	GameWrapper();
	~GameWrapper();

	void runGame();

	void splitAsteroid(Asteroid * oldAst); // Makes two new asteroids based on the parameter asteroid
	bool checkSplit(Asteroid * oldAst); // Returns true or false depending on 
	
	bool checkCollision(Laser * laser, Asteroid * asteroid);
	bool checkCollision(Ship * ship, Asteroid * asteroid);

	void refreshLevel(int n, sf::Texture * pText); // creates 4 + n asteroids in four off screen locations
	void drawAsteroidList(sf::RenderWindow & w);

	//void drawBorder(int score, int lives, sf::Texture * pText, sf::Font * pFont, sf::RenderWindow & window);
private:
	sf::Texture * mpAstText;
	sf::Texture * mpLaserText;
	sf::Texture * mpBorderText;
	//sf::Texture * mpShipText;
	sf::RenderWindow mWindow;
	
	List<Asteroid *> mAstList;
	List<Laser *> mLaserList;
	sf::Event mEvent;
};