// overall wrapper class
// controles all rendering and exicutes all motion
// detects interactions and initiates proper reactions

#pragma once
#include "Ship.h"
#include "Laser.h"
#include "Asteroid.h"
#include "List.h"
#include "Universal.h"
#include <cmath>
#include "stats.h"

class GameWrapper
{
public:
	GameWrapper();
	~GameWrapper();

	void runGame();
	void garbageCollector();

	void splitAsteroid(Asteroid * oldAst); // Makes two new asteroids based on the parameter asteroid
	bool checkSplit(Asteroid * oldAst); // Returns true or false depending on 
	
	double checkDist(sf::Vector2f & v1, sf::Vector2f & v2);

	bool checkCollision(Laser * laser, Asteroid * asteroid); // checks for laser vs asteroid collision; maybe kinda works
	bool checkCollision(Ship & ship, Asteroid * asteroid); // checks for ship vs asteroid collision; maybe kinda works

	void GameWrapper::refreshLevel(int n, sf::Texture * pText);

	//
	void drawAsteroidList(sf::RenderWindow & w);
	void drawLaserList(sf::RenderWindow & w);

	// moves a whole list of the type
	void moveLaserList();
	void moveAsteroidList(); // dosent work yet

	void astListBoundCheck();


	//void drawBorder(int score, int lives, sf::Texture * pText, sf::Font * pFont, sf::RenderWindow & window);
private:
	sf::Texture * mpAstText;
	sf::Texture * mpLaserText;
	sf::Texture * mpBorderText;
	//sf::Texture * mpShipText;
	sf::RenderWindow mWindow;
	Stats mScore;
	List<Asteroid *> mAstList;
	List<Laser *> mLaserList;
	sf::Event mEvent;
};