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

	void splitAsteroid(Asteroid * oldAst); // Makes two new asteroids based on the parameter asteroid
	bool checkSplit(Asteroid * oldAst); // Returns true or false depending on 
private:
	sf::Texture * mpAstText;
	sf::Texture * mpLaserText;
	//sf::Texture * mpShipText;
	sf::RenderWindow mWindow;
	
	List<Asteroid *> mAstList;
	List<Laser *> mLaserList;
	sf::Event mEvent;
};