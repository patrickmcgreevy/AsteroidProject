// overall wrapper class
// controles all rendering and exicutes all motion
// detects interactions and initiates proper reactions

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
	
	bool checkCollision(Laser * laser, Asteroid * asteroid); // checks for laser vs asteroid collision
	bool checkCollision(Ship * ship, Asteroid * asteroid); // checks for ship vs asteroid collision

	void GameWrapper::refreshLevel(int n, sf::Texture * pText);

	//
	void drawAsteroidList(sf::RenderWindow & w);
	void drawLaserList(sf::RenderWindow & w);

	// moves a whole list of the type
	void moveLaserList();
	void moveAsteroidList(); // dosent work yet


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